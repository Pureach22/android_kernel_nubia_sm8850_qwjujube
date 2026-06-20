#include "defs.h"

extern __int64 tpd_set_frame_data(__int64 a1, unsigned int a2, __int64 a3);

__int64 sub_30B14(__int64 a1, unsigned int a2, __int64 a3)
{
  return tpd_set_frame_data(a1, a2, a3);
}
