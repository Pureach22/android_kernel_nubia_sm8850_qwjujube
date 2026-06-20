#ifndef _GH_MEM_NOTIFIER_H
#define _GH_MEM_NOTIFIER_H

#include <linux/types.h>

enum gh_mem_notifier_tag {
    GH_MEM_NOTIFIER_TAG_DISPLAY = 1,
    GH_MEM_NOTIFIER_TAG_TOUCH_PRIMARY = 2,
    GH_MEM_NOTIFIER_TAG_TOUCH_SECONDARY = 3,
};

static inline void *gh_mem_notifier_register(enum gh_mem_notifier_tag tag, void *cb, void *data) { return (void *)1; }
static inline void gh_mem_notifier_unregister(void *cookie) { }

#endif
