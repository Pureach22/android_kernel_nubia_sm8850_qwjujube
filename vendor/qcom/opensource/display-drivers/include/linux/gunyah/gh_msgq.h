#ifndef _GH_MSGQ_H
#define _GH_MSGQ_H

#include <linux/types.h>

#define GH_MSGQ_MAX_MSG_SIZE_BYTES 240
#define GH_MSGQ_TX_PUSH 1
#define GH_MSGQ_LABEL_DISPLAY 1

static inline int gh_msgq_recv(void *h, void *b, size_t s, size_t *rs, u32 f) { return -1; }
static inline int gh_msgq_send(void *h, void *m, size_t s, u32 f) { return -1; }
static inline void *gh_msgq_register(u32 l) { return NULL; }
static inline void gh_msgq_unregister(void *h) { }

#endif
