#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kprobes.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/delay.h>

/* Structures mapped from static analysis */
struct kgsl_pwrlevel {
	unsigned int gpu_freq;
	unsigned int bus_freq;
	unsigned int bus_min;
	unsigned int bus_max;
	unsigned int acd_level;
	unsigned int cx_level;
	unsigned int voltage_level;
};

struct kgsl_pwrctrl {
	/* Struct alignment based on SM8550 GKI / kgsl_device layout */
	char padding[9144];
	struct kgsl_pwrlevel pwrlevels[32];
	unsigned int min_pwrlevel;
	unsigned int max_pwrlevel;
	unsigned int reserved;
	unsigned int num_pwrlevels;
};

struct kgsl_device {
	char padding[152];
	struct kgsl_pwrctrl pwrctrl;
};

/* Symbol resolutions via kprobes */
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

void ksu_adreno_overclock_init(void)
{
	struct kgsl_device *device;
	struct kgsl_pwrlevel *max_pwr;
	
	pr_info("adreno_overclock: Initializing injection module...\n");

	local_kgsl_get_device = (kgsl_get_device_t)resolve_symbol("kgsl_get_device");
	if (!local_kgsl_get_device) {
		pr_err("adreno_overclock: Failed to resolve kgsl_get_device symbol!\n");
		return;
	}

	/* Get GPU device ID 0 (Adreno 740/750) */
	device = local_kgsl_get_device(0);
	if (!device) {
		pr_err("adreno_overclock: Failed to retrieve kgsl_device[0]!\n");
		return;
	}

	max_pwr = &device->pwrctrl.pwrlevels[0];
	pr_info("adreno_overclock: Current max GPU freq: %u Hz, voltage: 0x%x\n", 
		max_pwr->gpu_freq, max_pwr->voltage_level);

	/* Inject Overclock 1230MHz and Overvolt stabilization level 0x1d0 (CPR 53) */
	if (max_pwr->gpu_freq == 1200000000) {
		max_pwr->gpu_freq = 1230000000;
		max_pwr->voltage_level = 0x1d0; /* Set to overvolted CPR index */
		max_pwr->cx_level = 64;         /* Lock to Super Turbo corner */
		pr_info("adreno_overclock: Injected 1230MHz overclock successfully!\n");
	} else {
		pr_warn("adreno_overclock: Unexpected initial frequency %u Hz, aborting injection.\n", 
			max_pwr->gpu_freq);
	}
}
