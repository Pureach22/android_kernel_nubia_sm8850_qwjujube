#ifndef _MSM_SDE_SOCINFO_H_
#define _MSM_SDE_SOCINFO_H_

#include_next <soc/qcom/socinfo.h>

#define PART_DISPLAY SOCINFO_PART_DISPLAY

static inline int socinfo_get_part_info(u32 part) { return 0; }
static inline int socinfo_get_part_count(u32 part) { return 0; }
static inline void socinfo_get_subpart_info(u32 part, void *info, u32 count) { }

#endif
