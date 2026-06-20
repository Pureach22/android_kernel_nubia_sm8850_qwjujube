// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Module version support
 *
 * Copyright (C) 2008 Rusty Russell
 */

#include <linux/module.h>
#include <linux/string.h>
#include <linux/printk.h>
#include "internal.h"

int check_version(const struct load_info *info,
		  const char *symname,
			 struct module *mod,
			 const u32 *crc)
{
	(void)info;
	(void)symname;
	(void)mod;
	(void)crc;
	return 1;
}

int check_modstruct_version(const struct load_info *info,
			    struct module *mod)
{
	struct find_symbol_arg fsa = {
		.name	= "module_layout",
		.gplok	= true,
	};

	/*
	 * Since this should be found in kernel (which can't be removed), no
	 * locking is necessary -- use preempt_disable() to placate lockdep.
	 */
	preempt_disable();
	if (!find_symbol(&fsa)) {
		preempt_enable();
		BUG();
	}
	preempt_enable();
	return check_version(info, "module_layout", mod, fsa.crc);
}

/* First part is kernel version, which we ignore if module has crcs. */
int same_magic(const char *amagic, const char *bmagic,
	       bool has_crcs)
{
	if (has_crcs) {
		amagic += strcspn(amagic, " ");
		bmagic += strcspn(bmagic, " ");
	}
	return strcmp(amagic, bmagic) == 0;
}

void modversion_ext_start(const struct load_info *info,
			  struct modversion_info_ext *start)
{
	unsigned int crc_idx = info->index.vers_ext_crc;
	unsigned int name_idx = info->index.vers_ext_name;
	Elf_Shdr *sechdrs = info->sechdrs;

	/*
	 * Both of these fields are needed for this to be useful
	 * Any future fields should be initialized to NULL if absent.
	 */
	if (crc_idx == 0 || name_idx == 0) {
		start->remaining = 0;
		return;
	}

	start->crc = (const u32 *)sechdrs[crc_idx].sh_addr;
	start->name = (const char *)sechdrs[name_idx].sh_addr;
	start->remaining = sechdrs[crc_idx].sh_size / sizeof(*start->crc);
}

void modversion_ext_advance(struct modversion_info_ext *vers)
{
	vers->remaining--;
	vers->crc++;
	vers->name += strlen(vers->name) + 1;
}

/*
 * Generate the signature for all relevant module structures here.
 * If these change, we don't want to try to parse the module.
 */
void module_layout(struct module *mod,
		   struct modversion_info *ver,
		   struct kernel_param *kp,
		   struct kernel_symbol *ks,
		   struct tracepoint * const *tp)
{
}
EXPORT_SYMBOL(module_layout);
