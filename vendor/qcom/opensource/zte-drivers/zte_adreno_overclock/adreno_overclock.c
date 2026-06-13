#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kprobes.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/delay.h>

#include "kgsl_device.h"
#include "kgsl_pwrctrl.h"

typedef struct kgsl_device *(*kgsl_get_device_t)(int id);
static kgsl_get_device_t local_kgsl_get_device = NULL;

static int kp_dummy_pre(struct kprobe *p, struct pt_regs *regs)
{
	return 0;
}

static struct kprobe kallsyms_kp = {
	.symbol_name = "kallsyms_lookup_name",
	.pre_handler = kp_dummy_pre,
};

static void *resolve_symbol(const char *name)
{
	typedef unsigned long (*kallsyms_lookup_name_t)(const char *name);
	kallsyms_lookup_name_t lookup_fn;
	void *addr = NULL;

	if (register_kprobe(&kallsyms_kp) == 0) {
		lookup_fn = (kallsyms_lookup_name_t)kallsyms_kp.addr;
		unregister_kprobe(&kallsyms_kp);
		if (lookup_fn) {
			addr = (void *)lookup_fn(name);
		}
	}
	return addr;
}

static int __init adreno_overclock_init(void)
{
	struct kgsl_device *device;
	struct kgsl_pwrlevel *max_pwr;
	
	pr_info("adreno_overclock: Dynamic injection module loading...\n");

	local_kgsl_get_device = (kgsl_get_device_t)resolve_symbol("kgsl_get_device");
	if (!local_kgsl_get_device) {
		pr_err("adreno_overclock: Failed to resolve kgsl_get_device symbol!\n");
		return -ENODEV;
	}

	device = local_kgsl_get_device(0);
	if (!device) {
		pr_err("adreno_overclock: Failed to retrieve kgsl_device[0]!\n");
		return -ENODEV;
	}

	max_pwr = &device->pwrctrl.pwrlevels[0];
	pr_info("adreno_overclock: Freq before: %u Hz, voltage: 0x%x\n", 
		max_pwr->gpu_freq, max_pwr->voltage_level);

	if (max_pwr->gpu_freq == 1200000000) {
		max_pwr->gpu_freq = 1230000000;
		max_pwr->voltage_level = 0x1d0;
		max_pwr->cx_level = 64;
		pr_info("adreno_overclock: Dynamically injected 1230MHz overclock successfully!\n");
	} else {
		pr_warn("adreno_overclock: Unexpected initial frequency %u Hz. Forcing anyway...\n", 
			max_pwr->gpu_freq);
		max_pwr->gpu_freq = 1230000000;
		max_pwr->voltage_level = 0x1d0;
		max_pwr->cx_level = 64;
	}
	return 0;
}

static void __exit adreno_overclock_exit(void)
{
	pr_info("adreno_overclock: Dynamic injection module unloaded.\n");
}

module_init(adreno_overclock_init);
module_exit(adreno_overclock_exit);

MODULE_DESCRIPTION("Dynamic Adreno 750 Overclock and Overvolt Injector for NX809J");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Antigravity");
