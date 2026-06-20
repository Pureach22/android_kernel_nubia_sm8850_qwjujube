#ifndef _GH_RM_DRV_H
#define _GH_RM_DRV_H

#include <linux/types.h>
#include <linux/version.h>

struct notifier_block;

typedef u32 gh_memparcel_handle_t;
typedef u16 gh_vmid_t;

#define GH_TRUSTED_VM 1

enum gh_vm_names {
    GH_VM_NAME_PRIMARY = 0,
    GH_VM_NAME_TRUSTED = 1,
};

#define GH_SELF_VM 0x100
#ifndef GH_PRIMARY_VM
#define GH_PRIMARY_VM 0x0
#endif

enum gh_rm_notif_type {
    GH_RM_NOTIF_MEM_SHARED = 1,
    GH_RM_NOTIF_VM_STATUS = 2,
    GH_RM_NOTIF_VM_IRQ_RELEASED = 3,
    GH_RM_NOTIF_MEM_RELEASED = 4,
};

enum gh_rm_vm_status {
    GH_RM_VM_STATUS_READY = 1,
    GH_RM_VM_STATUS_RESET = 2,
};

struct gh_rm_notif_vm_status_payload {
    gh_vmid_t vmid;
    u32 vm_status;
};

struct gh_rm_notif_mem_released_payload {
    u32 mem_handle;
    u32 label;
};

enum gh_rm_trans_type {
    GH_RM_TRANS_TYPE_LEND = 1,
};

enum gh_rm_mem_type {
    GH_RM_MEM_TYPE_NORMAL = 0,
    GH_RM_MEM_TYPE_IO = 1,
};

#define GH_RM_MEM_NOTIFY_OWNER_RELEASED 1
#define GH_RM_MEM_NOTIFY_RECIPIENT_SHARED 2
#define GH_RM_MEM_ACCEPT_VALIDATE_ACL_ATTRS 1
#define GH_RM_MEM_ACCEPT_VALIDATE_LABEL 1
#define GH_RM_MEM_ACCEPT_DONE 1

#define GH_RM_ACL_X BIT(0)
#define GH_RM_ACL_W BIT(1)
#define GH_RM_ACL_R BIT(2)

struct gh_rm_notif_mem_shared_payload {
    u32 mem_handle;
    u32 label;
    u32 trans_type;
};

struct gh_sgl_entry {
    u64 ipa_base;
    u64 size;
};

struct gh_sgl_desc {
    u32 n_sgl_entries;
    struct gh_sgl_entry sgl_entries[];
};

struct gh_acl_entry {
    gh_vmid_t vmid;
    u8 perms;
    u8 reserved;
};

struct gh_acl_desc {
    u32 n_acl_entries;
    struct gh_acl_entry acl_entries[];
};

struct gh_vmid_entry {
    gh_vmid_t vmid;
};

struct gh_notify_vmid_desc {
    u32 n_vmid_entries;
    struct gh_vmid_entry vmid_entries[];
};

static inline int gh_rm_mem_release(int handle, u32 flags) { return 0; }
static inline int ghd_rm_mem_reclaim(int handle, u32 flags) { return 0; }
static inline int gh_rm_mem_notify(int handle, u32 event, u32 tag, void *flags) { return 0; }
static inline struct gh_sgl_desc *gh_rm_mem_accept(int handle, u32 mem_type, u32 trans_type, u32 flags, u32 label, struct gh_acl_desc *acl, void *a, void *b, u32 c) { return NULL; }
static inline int ghd_rm_mem_lend(u32 type, u32 a, u32 label, void *acl, void *sgl, void *b, u32 *handle) { return 0; }
static inline int ghd_rm_mem_share(u32 type, u32 a, u32 label, void *acl, void *sgl, void *b, u32 *handle) { return 0; }
static inline int ghd_rm_get_vmid(u32 type, u16 *vmid) { return 0; }
static inline int gh_rm_get_vmid(u32 type, u16 *vmid) { return 0; }

static inline int gh_rm_register_notifier(struct notifier_block *nb) { return 0; }
static inline int gh_rm_unregister_notifier(struct notifier_block *nb) { return 0; }

#endif
