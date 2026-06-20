#ifndef _GH_IRQ_LEND_H
#define _GH_IRQ_LEND_H

#include <linux/types.h>

enum gh_irq_label {
    GH_IRQ_LABEL_INVALID = 0,
    GH_IRQ_LABEL_SDE = 1,
    GH_IRQ_LABEL_TRUSTED_TOUCH_PRIMARY = 2,
    GH_IRQ_LABEL_TRUSTED_TOUCH_SECONDARY = 3,
};

#ifndef GH_TRUSTED_VM
#define GH_TRUSTED_VM 2
#endif
#ifndef GH_PRIMARY_VM
#define GH_PRIMARY_VM 0
#endif

typedef void (*gh_irq_release_handler_t)(void *, unsigned long, enum gh_irq_label);

static inline int gh_irq_lend_v2(u32 label, u32 vmid, int irq, gh_irq_release_handler_t handler, void *data) { return 0; }
static inline int gh_irq_reclaim(u32 label) { return 0; }
static inline int gh_irq_lend_notify(u32 label) { return 0; }
static inline int gh_irq_release(u32 label) { return 0; }
static inline int gh_irq_release_notify(u32 label) { return 0; }
static inline int gh_irq_accept(u32 label, int a, u32 b) { return 0; }
static inline int gh_irq_wait_for_lend_v2(u32 label, u32 vmid, void *a, void *b) { return 0; }

#endif
