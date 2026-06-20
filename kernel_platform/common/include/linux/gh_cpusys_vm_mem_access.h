#ifndef _GH_CPUSYS_VM_MEM_ACCESS_H_
#define _GH_CPUSYS_VM_MEM_ACCESS_H_

#include <linux/types.h>

struct gh_cpusys_vm_share_mem_info {
    u64 ipa;
    u64 size;
};

static inline int gh_cpusys_vm_get_share_mem_info(void *res)
{
    return 0;
}

#endif
