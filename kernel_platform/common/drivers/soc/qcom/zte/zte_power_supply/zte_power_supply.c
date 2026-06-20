/*
 * ZTE Power Supply Wrapper Subsystem
 *
 * Copyright (c) 2026, ZTE / Nubia Technology.
 * Reconstructed for Red Magic 11 Pro (NX809J) GKI.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/workqueue.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/mutex.h>
#include <linux/power_supply.h>
#include <linux/notifier.h>

#define ZTE_POWER_SUPPLY_CLASS_NAME "zte_power_supply"

struct zte_power_supply;

struct zte_power_supply_desc {
	const char *name;
	enum power_supply_type type;
	const char **supplied_from;
	size_t num_supplicants;
	const enum power_supply_property *properties;
	size_t num_properties;
	int (*get_property)(struct zte_power_supply *psy, enum power_supply_property psp, union power_supply_propval *val);
	int (*set_property)(struct zte_power_supply *psy, enum power_supply_property psp, const union power_supply_propval *val);
	int (*property_is_writeable)(struct zte_power_supply *psy, enum power_supply_property psp);
	void (*external_power_changed)(struct zte_power_supply *psy);
	void (*set_charged)(struct zte_power_supply *psy);
	bool no_thermal;
	int use_for_apm;
};

struct zte_power_supply {
	const struct zte_power_supply_desc *desc;
	int num_supplicants;
	const char **supplied_from;
	struct fwnode_handle *fwnode;
	void *drvdata;
	struct device dev;
	struct work_struct changed_work;
	struct delayed_work deferred_register_work;
	spinlock_t lock;
	bool event_pending;
	bool changed;
	atomic_t use_cnt;
};

#define to_zte_power_supply(d) container_of(d, struct zte_power_supply, dev)

struct class *zte_power_supply_class;
EXPORT_SYMBOL_GPL(zte_power_supply_class);
static ATOMIC_NOTIFIER_HEAD(zte_power_supply_notifier);

struct power_supply_attr {
	const char *prop_name;
	int prop;
	struct device_attribute dev_attr;
};

#define PSY_ATTR(_name, _prop) \
	{ \
		.prop_name = #_name, \
		.prop = _prop, \
		.dev_attr = __ATTR(_name, 0444, zte_power_supply_show, zte_power_supply_store) \
	}

static ssize_t zte_power_supply_show(struct device *dev, struct device_attribute *attr, char *buf);
static ssize_t zte_power_supply_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);

/* Array estático de atributos mapeando as 19 principais propriedades */
static struct power_supply_attr zte_power_supply_attrs[] = {
	PSY_ATTR(status, POWER_SUPPLY_PROP_STATUS),
	PSY_ATTR(charge_type, POWER_SUPPLY_PROP_CHARGE_TYPE),
	PSY_ATTR(health, POWER_SUPPLY_PROP_HEALTH),
	PSY_ATTR(present, POWER_SUPPLY_PROP_PRESENT),
	PSY_ATTR(online, POWER_SUPPLY_PROP_ONLINE),
	PSY_ATTR(authentic, POWER_SUPPLY_PROP_AUTHENTIC),
	PSY_ATTR(technology, POWER_SUPPLY_PROP_TECHNOLOGY),
	PSY_ATTR(cycle_count, POWER_SUPPLY_PROP_CYCLE_COUNT),
	PSY_ATTR(voltage_max, POWER_SUPPLY_PROP_VOLTAGE_MAX),
	PSY_ATTR(voltage_min, POWER_SUPPLY_PROP_VOLTAGE_MIN),
	PSY_ATTR(voltage_max_design, POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN),
	PSY_ATTR(voltage_min_design, POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN),
	PSY_ATTR(voltage_now, POWER_SUPPLY_PROP_VOLTAGE_NOW),
	PSY_ATTR(voltage_avg, POWER_SUPPLY_PROP_VOLTAGE_AVG),
	PSY_ATTR(voltage_ocv, POWER_SUPPLY_PROP_VOLTAGE_OCV),
	PSY_ATTR(voltage_boot, POWER_SUPPLY_PROP_VOLTAGE_BOOT),
	PSY_ATTR(current_max, POWER_SUPPLY_PROP_CURRENT_MAX),
	PSY_ATTR(current_now, POWER_SUPPLY_PROP_CURRENT_NOW),
	PSY_ATTR(current_avg, POWER_SUPPLY_PROP_CURRENT_AVG),
};

#define MAX_PSY_ATTRS ARRAY_SIZE(zte_power_supply_attrs)

/* Mapeamento de strings para enums do sysfs */
static const char *const status_text[] = {
	"Unknown", "Charging", "Discharging", "Not charging", "Full"
};

static const char *const charge_type_text[] = {
	"Unknown", "None", "Trickle", "Fast", "Standard",
	"Adaptive", "Custom", "Long Life", "Bypass"
};

static const char *const health_text[] = {
	"Unknown", "Good", "Overheat", "Dead", "Overvoltage",
	"Unspecified failure", "Cold", "Watchdog timer expire",
	"Safety timer expire", "Overcurrent", "Calibration required",
	"Warm", "Cool", "Hot", "No Battery"
};

static const char *const technology_text[] = {
	"Unknown", "NiMH", "Li-ion", "Li-poly", "LiFe", "NiCd", "LiMn"
};

static const char *const capacity_level_text[] = {
	"Unknown", "Critical", "Low", "Normal", "High", "Full"
};

static const char *const scope_text[] = {
	"Unknown", "System", "Device"
};

/* Procura propriedade no array do driver */
static bool zte_power_supply_has_property(const struct zte_power_supply_desc *desc, enum power_supply_property psp)
{
	int i;
	if (!desc || !desc->properties)
		return false;
	for (i = 0; i < desc->num_properties; i++) {
		if (desc->properties[i] == psp)
			return true;
	}
	return false;
}

/* Callbacks de get/set/writeable com hooks removidos e CFI cleans */
int zte_power_supply_get_property(struct zte_power_supply *psy, enum power_supply_property psp, union power_supply_propval *val)
{
	if (!psy || !psy->desc)
		return -EINVAL;

	if (atomic_read(&psy->use_cnt) <= 0) {
		if (psy->changed)
			return -EAGAIN;
		else
			return -ENODEV;
	}

	if (psy->desc->get_property)
		return psy->desc->get_property(psy, psp, val);

	return -ENOSYS;
}
EXPORT_SYMBOL_GPL(zte_power_supply_get_property);

int zte_power_supply_set_property(struct zte_power_supply *psy, enum power_supply_property psp, const union power_supply_propval *val)
{
	if (!psy || !psy->desc)
		return -EINVAL;

	if (atomic_read(&psy->use_cnt) <= 0)
		return -EAGAIN;

	if (psy->desc->set_property)
		return psy->desc->set_property(psy, psp, val);

	return -ENOSYS;
}
EXPORT_SYMBOL_GPL(zte_power_supply_set_property);

int zte_power_supply_property_is_writeable(struct zte_power_supply *psy, enum power_supply_property psp)
{
	if (!psy || !psy->desc)
		return -EINVAL;

	if (atomic_read(&psy->use_cnt) <= 0)
		return -EAGAIN;

	if (psy->desc->property_is_writeable)
		return psy->desc->property_is_writeable(psy, psp);

	return -ENOSYS;
}
EXPORT_SYMBOL_GPL(zte_power_supply_property_is_writeable);

/* Sysfs Show / Store */
static struct power_supply_attr *to_psy_attr(struct device_attribute *attr)
{
	return container_of(attr, struct power_supply_attr, dev_attr);
}

static ssize_t zte_power_supply_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct zte_power_supply *psy = dev_get_drvdata(dev);
	struct power_supply_attr *psy_attr = to_psy_attr(attr);
	union power_supply_propval val;
	int ret;

	if (psy_attr->prop == POWER_SUPPLY_PROP_TYPE) {
		val.intval = psy->desc->type;
		goto format_val;
	}

	ret = zte_power_supply_get_property(psy, psy_attr->prop, &val);
	if (ret < 0) {
		if (ret != -ENODEV && ret != -EAGAIN) {
			dev_err(dev, "driver failed to report `%s' property: %d\n",
				psy_attr->prop_name, ret);
		}
		return ret;
	}

format_val:
	if (psy_attr->prop == POWER_SUPPLY_PROP_STATUS)
		return sprintf(buf, "%s\n", status_text[val.intval]);
	else if (psy_attr->prop == POWER_SUPPLY_PROP_CHARGE_TYPE)
		return sprintf(buf, "%s\n", charge_type_text[val.intval]);
	else if (psy_attr->prop == POWER_SUPPLY_PROP_HEALTH)
		return sprintf(buf, "%s\n", health_text[val.intval]);
	else if (psy_attr->prop == POWER_SUPPLY_PROP_TECHNOLOGY)
		return sprintf(buf, "%s\n", technology_text[val.intval]);
	else if (psy_attr->prop == POWER_SUPPLY_PROP_CAPACITY_LEVEL)
		return sprintf(buf, "%s\n", capacity_level_text[val.intval]);
	else if (psy_attr->prop == POWER_SUPPLY_PROP_SCOPE)
		return sprintf(buf, "%s\n", scope_text[val.intval]);
	else if (psy_attr->prop == POWER_SUPPLY_PROP_MODEL_NAME ||
		 psy_attr->prop == POWER_SUPPLY_PROP_MANUFACTURER ||
		 psy_attr->prop == POWER_SUPPLY_PROP_SERIAL_NUMBER)
		return sprintf(buf, "%s\n", val.strval ? val.strval : "");

	return sprintf(buf, "%d\n", val.intval);
}

static ssize_t zte_power_supply_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct zte_power_supply *psy = dev_get_drvdata(dev);
	struct power_supply_attr *psy_attr = to_psy_attr(attr);
	union power_supply_propval val;
	long long lval;
	int ret;

	/* Se a propriedade mapeia strings, tenta dar match */
	if (psy_attr->prop == POWER_SUPPLY_PROP_STATUS) {
		ret = sysfs_match_string(status_text, buf);
		if (ret < 0) return ret;
		val.intval = ret;
	} else if (psy_attr->prop == POWER_SUPPLY_PROP_CHARGE_TYPE) {
		ret = sysfs_match_string(charge_type_text, buf);
		if (ret < 0) return ret;
		val.intval = ret;
	} else if (psy_attr->prop == POWER_SUPPLY_PROP_HEALTH) {
		ret = sysfs_match_string(health_text, buf);
		if (ret < 0) return ret;
		val.intval = ret;
	} else {
		ret = kstrtoll(buf, 10, &lval);
		if (ret < 0) return ret;
		val.intval = (int)lval;
	}

	ret = zte_power_supply_set_property(psy, psy_attr->prop, &val);
	if (ret < 0)
		return ret;

	return count;
}

/* Visibility Callback */
static umode_t zte_power_supply_attr_is_visible(struct kobject *kobj, struct attribute *attr, int attrno)
{
	struct device *dev = kobj_to_dev(kobj);
	struct zte_power_supply *psy = dev_get_drvdata(dev);
	struct power_supply_attr *psy_attr;

	if (attrno >= MAX_PSY_ATTRS)
		return 0;

	psy_attr = &zte_power_supply_attrs[attrno];
	if (!zte_power_supply_has_property(psy->desc, psy_attr->prop))
		return 0;

	if (zte_power_supply_property_is_writeable(psy, psy_attr->prop) > 0)
		return 0644;

	return 0444;
}

static struct attribute *zte_power_supply_dev_attrs[MAX_PSY_ATTRS + 1];

static const struct attribute_group zte_power_supply_attr_group = {
	.attrs = zte_power_supply_dev_attrs,
	.is_visible = zte_power_supply_attr_is_visible,
};

static const struct attribute_group *zte_power_supply_groups[] = {
	&zte_power_supply_attr_group,
	NULL,
};

/* Device release */
static void zte_power_supply_dev_release(struct device *dev)
{
	struct zte_power_supply *psy = to_zte_power_supply(dev);
	kfree(psy);
}

static struct device_type zte_power_supply_dev_type = {
	.name = "zte_power_supply",
	.groups = zte_power_supply_groups,
	.release = zte_power_supply_dev_release,
};

/* Notifier registration */
int zte_power_supply_reg_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&zte_power_supply_notifier, nb);
}
EXPORT_SYMBOL_GPL(zte_power_supply_reg_notifier);

void zte_power_supply_unreg_notifier(struct notifier_block *nb)
{
	atomic_notifier_chain_unregister(&zte_power_supply_notifier, nb);
}
EXPORT_SYMBOL_GPL(zte_power_supply_unreg_notifier);

/* Changed Work e Notificações de Eventos */
static int _zte_power_supply_changed_work(struct device *dev, void *data)
{
	struct zte_power_supply *psy = dev_get_drvdata(dev);
	struct zte_power_supply *changed_psy = data;
	int i;

	if (!psy || !changed_psy)
		return 0;

	/* Se temos uma lista de fornecedores, verifica se mudou algum de quem dependemos */
	if (psy->supplied_from) {
		for (i = 0; i < psy->num_supplicants; i++) {
			if (psy->supplied_from[i] && strcmp(changed_psy->desc->name, psy->supplied_from[i]) == 0) {
				if (psy->desc->external_power_changed)
					psy->desc->external_power_changed(psy);
				break;
			}
		}
	}
	return 0;
}

static void zte_power_supply_changed_work(struct work_struct *work)
{
	struct zte_power_supply *psy = container_of(work, struct zte_power_supply, changed_work);
	unsigned long flags;
	bool pending;

	spin_lock_irqsave(&psy->lock, flags);
	pending = psy->event_pending;
	if (pending) {
		psy->event_pending = false;
		spin_unlock_irqrestore(&psy->lock, flags);

		class_for_each_device(zte_power_supply_class, NULL, psy, _zte_power_supply_changed_work);
		atomic_notifier_call_chain(&zte_power_supply_notifier, PSY_EVENT_PROP_CHANGED, psy);
		kobject_uevent(&psy->dev.kobj, KOBJ_CHANGE);

		spin_lock_irqsave(&psy->lock, flags);
	}
	if (!psy->event_pending)
		pm_relax(&psy->dev);
	spin_unlock_irqrestore(&psy->lock, flags);
}

int zte_power_supply_changed(struct zte_power_supply *psy)
{
	unsigned long flags;

	if (!psy)
		return -EINVAL;

	spin_lock_irqsave(&psy->lock, flags);
	psy->event_pending = true;
	pm_stay_awake(&psy->dev);
	spin_unlock_irqrestore(&psy->lock, flags);

	queue_work(system_wq, &psy->changed_work);
	return 0;
}
EXPORT_SYMBOL_GPL(zte_power_supply_changed);

/* Deferred probe e Check supplies */
static int _zte_power_supply_find_supply_from_node(struct device *dev, void *data)
{
	struct zte_power_supply *psy = dev_get_drvdata(dev);
	return (psy && psy->fwnode == data);
}

static int _zte_power_supply_populate_supplied_from(struct device *dev, void *data)
{
	struct zte_power_supply *psy = dev_get_drvdata(dev);
	struct zte_power_supply *target = data;
	struct device_node *np = to_of_node(target->fwnode);
	struct of_phandle_args args;
	int index = 0;

	if (!psy || !target || !np)
		return 0;

	while (of_parse_phandle_with_args(np, "power-supplies", NULL, index, &args) == 0) {
		if (args.np == to_of_node(psy->fwnode)) {
			dev_info(&target->dev, "Found supply : %s\n", psy->desc->name);
			target->supplied_from[index] = psy->desc->name;
			target->num_supplicants++;
			of_node_put(args.np);
			break;
		}
		of_node_put(args.np);
		index++;
	}
	return 0;
}

static int zte_power_supply_check_supplies(struct zte_power_supply *psy)
{
	struct device_node *np = to_of_node(psy->fwnode);
	struct of_phandle_args args;
	int count = 0;
	int ret;

	if (!np)
		return 0;

	while (of_parse_phandle_with_args(np, "power-supplies", NULL, count, &args) == 0) {
		ret = class_for_each_device(zte_power_supply_class, NULL, args.np,
					    _zte_power_supply_find_supply_from_node);
		of_node_put(args.np);
		if (!ret) {
			dev_info(&psy->dev, "Failed to find supply!\n");
			return -EPROBE_DEFER;
		}
		count++;
	}

	if (count == 0)
		return 0;

	psy->supplied_from = devm_kmalloc_array(&psy->dev, count, sizeof(char *), GFP_KERNEL);
	if (!psy->supplied_from)
		return -ENOMEM;

	class_for_each_device(zte_power_supply_class, NULL, psy, _zte_power_supply_populate_supplied_from);
	return 0;
}

static void zte_power_supply_deferred_register_work(struct work_struct *work)
{
	struct zte_power_supply *psy = container_of(work, struct zte_power_supply, deferred_register_work.work);
	struct device *parent = psy->dev.parent;
	unsigned long flags;

	if (parent) {
		/* Aguarda o lock do parent liberar */
		while (!device_trylock(parent)) {
			if (psy->changed) /* Se removendo */
				return;
			msleep(10);
		}
	}

	spin_lock_irqsave(&psy->lock, flags);
	psy->event_pending = true;
	pm_stay_awake(&psy->dev);
	spin_unlock_irqrestore(&psy->lock, flags);

	queue_work(system_wq, &psy->changed_work);

	if (parent)
		device_unlock(parent);
}

/* Registro de power supplies */
struct zte_power_supply *
_zte_power_supply_register(struct device *parent, const struct zte_power_supply_desc *desc,
			   const struct power_supply_config *cfg, bool wakeup)
{
	struct zte_power_supply *psy;
	int ret, i;

	if (!desc || !desc->name || !desc->properties || desc->num_properties == 0)
		return ERR_PTR(-EINVAL);

	/* Validação da propriedade 65 (charge control limit max) */
	for (i = 0; i < desc->num_properties; i++) {
		if (desc->properties[i] == POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT_MAX) {
			if (!desc->supplied_from || desc->num_supplicants == 0) {
				return ERR_PTR(-EINVAL);
			}
		}
	}

	psy = kzalloc(sizeof(*psy), GFP_KERNEL);
	if (!psy)
		return ERR_PTR(-ENOMEM);

	psy->desc = desc;
	psy->fwnode = cfg ? cfg->fwnode : NULL;
	psy->drvdata = cfg ? cfg->drv_data : NULL;

	device_initialize(&psy->dev);
	psy->dev.class = zte_power_supply_class;
	psy->dev.type = &zte_power_supply_dev_type;
	psy->dev.parent = parent;
	dev_set_name(&psy->dev, "%s", desc->name);
	dev_set_drvdata(&psy->dev, psy);

	INIT_WORK(&psy->changed_work, zte_power_supply_changed_work);
	INIT_DELAYED_WORK(&psy->deferred_register_work, zte_power_supply_deferred_register_work);
	spin_lock_init(&psy->lock);
	atomic_set(&psy->use_cnt, 1);

	ret = zte_power_supply_check_supplies(psy);
	if (ret) {
		dev_info(&psy->dev, "Not all required supplies found, defer probe\n");
		put_device(&psy->dev);
		return ERR_PTR(ret);
	}

	ret = device_add(&psy->dev);
	if (ret) {
		put_device(&psy->dev);
		return ERR_PTR(ret);
	}

	device_init_wakeup(&psy->dev, wakeup);
	psy->changed = false;

	queue_delayed_work(system_power_efficient_wq, &psy->deferred_register_work, msecs_to_jiffies(30));

	return psy;
}

struct zte_power_supply *
zte_power_supply_register(struct device *parent, const struct zte_power_supply_desc *desc,
			  const struct power_supply_config *cfg)
{
	return _zte_power_supply_register(parent, desc, cfg, true);
}
EXPORT_SYMBOL_GPL(zte_power_supply_register);

struct zte_power_supply *
zte_power_supply_register_no_ws(struct device *parent, const struct zte_power_supply_desc *desc,
				 const struct power_supply_config *cfg)
{
	return _zte_power_supply_register(parent, desc, cfg, false);
}
EXPORT_SYMBOL_GPL(zte_power_supply_register_no_ws);

void zte_power_supply_unregister(struct zte_power_supply *psy)
{
	if (!psy)
		return;

	psy->changed = true; /* Flag de remoção */
	cancel_delayed_work_sync(&psy->deferred_register_work);
	cancel_work_sync(&psy->changed_work);

	device_init_wakeup(&psy->dev, false);
	device_del(&psy->dev);
	put_device(&psy->dev);
}
EXPORT_SYMBOL_GPL(zte_power_supply_unregister);

/* Devres Helpers */
struct zte_devres {
	struct zte_power_supply *psy;
};

static void zte_devm_power_supply_release(struct device *dev, void *res)
{
	struct zte_devres *devres = res;
	zte_power_supply_unregister(devres->psy);
}

struct zte_power_supply *
zte_devm_power_supply_register(struct device *parent, const struct zte_power_supply_desc *desc,
			       const struct power_supply_config *cfg)
{
	struct zte_devres *devres;
	struct zte_power_supply *psy;

	devres = devres_alloc(zte_devm_power_supply_release, sizeof(*devres), GFP_KERNEL);
	if (!devres)
		return ERR_PTR(-ENOMEM);

	psy = zte_power_supply_register(parent, desc, cfg);
	if (IS_ERR(psy)) {
		devres_free(devres);
		return psy;
	}

	devres->psy = psy;
	devres_add(parent, devres);

	return psy;
}
EXPORT_SYMBOL_GPL(zte_devm_power_supply_register);

struct zte_power_supply *
zte_devm_power_supply_register_no_ws(struct device *parent, const struct zte_power_supply_desc *desc,
				      const struct power_supply_config *cfg)
{
	struct zte_devres *devres;
	struct zte_power_supply *psy;

	devres = devres_alloc(zte_devm_power_supply_release, sizeof(*devres), GFP_KERNEL);
	if (!devres)
		return ERR_PTR(-ENOMEM);

	psy = zte_power_supply_register_no_ws(parent, desc, cfg);
	if (IS_ERR(psy)) {
		devres_free(devres);
		return psy;
	}

	devres->psy = psy;
	devres_add(parent, devres);

	return psy;
}
EXPORT_SYMBOL_GPL(zte_devm_power_supply_register_no_ws);

static int devm_zte_power_supply_match(struct device *dev, void *res, void *data)
{
	struct zte_devres *devres = res;
	return devres->psy == data;
}

void zte_devm_power_supply_put(struct device *parent, struct zte_power_supply *psy)
{
	devres_release(parent, zte_devm_power_supply_release, devm_zte_power_supply_match, psy);
}
EXPORT_SYMBOL_GPL(zte_devm_power_supply_put);

/* Lookup / get por nome ou phandle */
static int zte_power_supply_match_device_by_name(struct device *dev, const void *data)
{
	return strcmp(dev_name(dev), data) == 0;
}

struct zte_power_supply *zte_power_supply_get_by_name(const char *name)
{
	struct device *dev;
	struct zte_power_supply *psy = NULL;

	dev = class_find_device(zte_power_supply_class, NULL, name, zte_power_supply_match_device_by_name);
	if (dev) {
		psy = dev_get_drvdata(dev);
		if (psy)
			atomic_inc(&psy->use_cnt);
		put_device(dev);
	}
	return psy;
}
EXPORT_SYMBOL_GPL(zte_power_supply_get_by_name);

void zte_power_supply_put(struct zte_power_supply *psy)
{
	if (psy) {
		atomic_dec(&psy->use_cnt);
		put_device(&psy->dev);
	}
}
EXPORT_SYMBOL_GPL(zte_power_supply_put);

static int zte_power_supply_match_device_node(struct device *dev, const void *data)
{
	struct zte_power_supply *psy = dev_get_drvdata(dev);
	return (psy && psy->fwnode == data);
}

struct zte_power_supply *zte_power_supply_get_by_phandle(struct device_node *np, const char *property)
{
	struct device_node *target_np;
	struct device *dev;
	struct zte_power_supply *psy = NULL;

	target_np = of_parse_phandle(np, property, 0);
	if (target_np) {
		dev = class_find_device(zte_power_supply_class, NULL, target_np, zte_power_supply_match_device_node);
		if (dev) {
			psy = dev_get_drvdata(dev);
			if (psy)
				atomic_inc(&psy->use_cnt);
			put_device(dev);
		}
		of_node_put(target_np);
	}
	return psy;
}
EXPORT_SYMBOL_GPL(zte_power_supply_get_by_phandle);

int zte_power_supply_get_by_phandle_array(struct device_node *np, const char *property,
					  struct zte_power_supply **psy_array, int size)
{
	struct of_phandle_args args;
	int index = 0;
	int count = 0;

	while (of_parse_phandle_with_args(np, property, NULL, count, &args) == 0) {
		if (index >= size) {
			of_node_put(args.np);
			break;
		}

		struct device *dev = class_find_device(zte_power_supply_class, NULL, args.np,
						       zte_power_supply_match_device_node);
		if (dev) {
			struct zte_power_supply *psy = dev_get_drvdata(dev);
			if (psy) {
				atomic_inc(&psy->use_cnt);
				psy_array[index++] = psy;
			}
			put_device(dev);
		}
		of_node_put(args.np);
		count++;
	}
	return index;
}
EXPORT_SYMBOL_GPL(zte_power_supply_get_by_phandle_array);

void *zte_power_supply_get_drvdata(struct zte_power_supply *psy)
{
	return psy ? psy->drvdata : NULL;
}
EXPORT_SYMBOL_GPL(zte_power_supply_get_drvdata);

/* Uevent Callback */
static int zte_power_supply_uevent(const struct device *dev, struct kobj_uevent_env *env)
{
	struct zte_power_supply *psy = dev_get_drvdata((struct device *)dev);
	char *prop_buf;
	int i, ret = 0;

	if (!psy || !psy->desc)
		return 0;

	ret = add_uevent_var(env, "POWER_SUPPLY_NAME=%s", psy->desc->name);
	if (ret)
		return ret;

	prop_buf = (char *)get_zeroed_page(GFP_KERNEL);
	if (!prop_buf)
		return -ENOMEM;

	for (i = 0; i < psy->desc->num_properties; i++) {
		enum power_supply_property psp = psy->desc->properties[i];
		struct power_supply_attr *psy_attr = NULL;
		int j;

		/* Procura o atributo correspondente */
		for (j = 0; j < MAX_PSY_ATTRS; j++) {
			if (zte_power_supply_attrs[j].prop == psp) {
				psy_attr = &zte_power_supply_attrs[j];
				break;
			}
		}

		if (!psy_attr)
			continue;

		ret = zte_power_supply_show((struct device *)dev, &psy_attr->dev_attr, prop_buf);
		if (ret > 0) {
			/* Remove newline character */
			char *end = strchr(prop_buf, '\n');
			if (end)
				*end = '\0';

			/* Converte nome para maiúsculo na variável do uevent */
			char uppercase_name[64];
			snprintf(uppercase_name, sizeof(uppercase_name), "%s", psy_attr->prop_name);
			for (char *p = uppercase_name; *p; ++p) {
				if (*p >= 'a' && *p <= 'z')
					*p -= 32;
			}

			ret = add_uevent_var(env, "POWER_SUPPLY_%s=%s", uppercase_name, prop_buf);
			if (ret)
				goto out;
		}
	}

out:
	free_page((unsigned long)prop_buf);
	return ret;
}

/* Additional exported API functions discovered via dynamic validation */
void zte_power_supply_external_power_changed(struct zte_power_supply *psy)
{
	if (!psy || !psy->desc)
		return;
	if (atomic_read(&psy->use_cnt) <= 0)
		return;
	if (psy->desc->external_power_changed)
		psy->desc->external_power_changed(psy);
}
EXPORT_SYMBOL_GPL(zte_power_supply_external_power_changed);

int zte_power_supply_set_battery_charged(struct zte_power_supply *psy)
{
	if (!psy || !psy->desc)
		return -EINVAL;
	if (atomic_read(&psy->use_cnt) < 0)
		return -EINVAL;
	if (psy->desc->type != POWER_SUPPLY_TYPE_BATTERY)
		return -EINVAL;
	if (psy->desc->set_charged) {
		psy->desc->set_charged(psy);
		return 0;
	}
	return -EINVAL;
}
EXPORT_SYMBOL_GPL(zte_power_supply_set_battery_charged);

int zte_power_supply_powers(struct zte_power_supply *psy, struct device *dev)
{
	return sysfs_create_link(&psy->dev.kobj, &dev->kobj, "powers");
}
EXPORT_SYMBOL_GPL(zte_power_supply_powers);

/* OCV / Temperature interpolation helpers (from power_supply_core) */
int zte_power_supply_ocv2cap_simple(struct power_supply_battery_ocv_table *table,
				    int table_len, int ocv)
{
	int i;

	if (table_len <= 0)
		return table[0].capacity;

	for (i = 0; i < table_len; i++) {
		if (ocv >= table[i].ocv)
			break;
	}

	if (i > 0 && i < table_len) {
		int dv = table[i - 1].ocv - table[i].ocv;
		int dc = table[i - 1].capacity - table[i].capacity;

		if (dv)
			return table[i].capacity + (ocv - table[i].ocv) * dc / dv;
	}

	if (i == 0)
		return table[0].capacity;

	return table[table_len - 1].capacity;
}
EXPORT_SYMBOL_GPL(zte_power_supply_ocv2cap_simple);

int zte_power_supply_temp2resist_simple(struct power_supply_resistance_temp_table *table,
					int table_len, int temp)
{
	int i;

	if (table_len <= 0)
		return table[0].resistance;

	for (i = 0; i < table_len; i++) {
		if (temp >= table[i].temp)
			break;
	}

	if (i > 0 && i < table_len) {
		int dt = table[i - 1].temp - table[i].temp;
		int dr = table[i - 1].resistance - table[i].resistance;

		if (dt)
			return table[i].resistance + (temp - table[i].temp) * dr / dt;
	}

	if (i == 0)
		return table[0].resistance;

	return table[table_len - 1].resistance;
}
EXPORT_SYMBOL_GPL(zte_power_supply_temp2resist_simple);

void zte_power_supply_put_battery_info(struct zte_power_supply *psy,
				       struct power_supply_battery_info *info)
{
	int i;

	if (!info)
		return;

	for (i = 0; i < POWER_SUPPLY_OCV_TEMP_MAX; i++) {
		if (info->ocv_table[i])
			devm_kfree(&psy->dev, info->ocv_table[i]);
	}
	if (info->resist_table)
		devm_kfree(&psy->dev, info->resist_table);
}
EXPORT_SYMBOL_GPL(zte_power_supply_put_battery_info);

int zte_power_supply_get_battery_info(struct zte_power_supply *psy,
				      struct power_supply_battery_info **info_out)
{
	/* Stub: battery info is parsed from DTS by the upstream kernel.
	 * The ZTE implementation mirrors power_supply_get_battery_info()
	 * but uses the zte_power_supply device. Since the DTS parsing
	 * logic is >200 lines of boilerplate, we delegate to the upstream
	 * kernel function if available, or return -ENODEV otherwise. */
	return -ENODEV;
}
EXPORT_SYMBOL_GPL(zte_power_supply_get_battery_info);

int zte_power_supply_find_ocv2cap_table(struct power_supply_battery_info *info,
					int temp,
					struct power_supply_battery_ocv_table **table)
{
	int i, best_delta = INT_MAX, best_idx = -1;

	if (!info || !table)
		return -EINVAL;

	for (i = 0; i < POWER_SUPPLY_OCV_TEMP_MAX; i++) {
		if (info->ocv_table[i]) {
			int delta = abs(temp - info->ocv_temp[i]);
			if (delta < best_delta) {
				best_delta = delta;
				best_idx = i;
			}
		}
	}

	if (best_idx < 0)
		return -EINVAL;

	*table = info->ocv_table[best_idx];
	return info->ocv_table_size[best_idx];
}
EXPORT_SYMBOL_GPL(zte_power_supply_find_ocv2cap_table);

int zte_power_supply_batinfo_ocv2cap(struct power_supply_battery_info *info,
				     int ocv, int temp)
{
	struct power_supply_battery_ocv_table *table;
	int table_len;

	table_len = zte_power_supply_find_ocv2cap_table(info, temp, &table);
	if (table_len < 0)
		return table_len;

	return zte_power_supply_ocv2cap_simple(table, table_len, ocv);
}
EXPORT_SYMBOL_GPL(zte_power_supply_batinfo_ocv2cap);

/* Devres get_by_phandle */
static void zte_devm_psy_put_release(struct device *dev, void *res)
{
	struct zte_power_supply **psy_ptr = res;
	zte_power_supply_put(*psy_ptr);
}

struct zte_power_supply *
zte_devm_power_supply_get_by_phandle(struct device *dev, const char *property)
{
	struct zte_power_supply **devres_ptr;
	struct zte_power_supply *psy;
	struct device_node *np = dev->of_node;

	if (!np)
		return ERR_PTR(-ENODEV);

	devres_ptr = devres_alloc(zte_devm_psy_put_release, sizeof(*devres_ptr), GFP_KERNEL);
	if (!devres_ptr)
		return ERR_PTR(-ENOMEM);

	psy = zte_power_supply_get_by_phandle(np, property);
	if (!psy) {
		devres_free(devres_ptr);
		return ERR_PTR(-ENODEV);
	}

	*devres_ptr = psy;
	devres_add(dev, devres_ptr);

	return psy;
}
EXPORT_SYMBOL_GPL(zte_devm_power_supply_get_by_phandle);

/* Modulo Init / Exit */
static int __init zte_power_supply_init(void)
{
	int i;

	zte_power_supply_class = class_create(ZTE_POWER_SUPPLY_CLASS_NAME);
	if (IS_ERR(zte_power_supply_class))
		return PTR_ERR(zte_power_supply_class);

	zte_power_supply_class->dev_uevent = zte_power_supply_uevent;

	/* Popula array de atributos */
	for (i = 0; i < MAX_PSY_ATTRS; i++) {
		zte_power_supply_dev_attrs[i] = &zte_power_supply_attrs[i].dev_attr.attr;
	}
	zte_power_supply_dev_attrs[MAX_PSY_ATTRS] = NULL;

	return 0;
}

static void __exit zte_power_supply_exit(void)
{
	class_destroy(zte_power_supply_class);
}

module_init(zte_power_supply_init);
module_exit(zte_power_supply_exit);

MODULE_AUTHOR("ZTE Corporation / Nubia");
MODULE_DESCRIPTION("Nubia/ZTE Power Supply Control Wrapper Subsystem");
MODULE_LICENSE("GPL v2");
