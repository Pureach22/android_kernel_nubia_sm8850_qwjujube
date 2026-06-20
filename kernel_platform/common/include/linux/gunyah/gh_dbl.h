#ifndef _GH_DBL_H_
#define _GH_DBL_H_

#include <linux/types.h>

typedef u64 gh_dbl_flags_t;

struct gh_dbl {
    void *priv;
};

static inline int gh_dbl_read_and_clean(struct gh_dbl *dbl, gh_dbl_flags_t *flags, u32 options)
{
    if (flags) *flags = 0;
    return 0;
}

static inline struct gh_dbl *gh_dbl_rx_register(u32 label, void (*cb)(int, void *), void *data)
{
    return (struct gh_dbl *)0xDEADBEEF; // Dummy handle
}

#endif
