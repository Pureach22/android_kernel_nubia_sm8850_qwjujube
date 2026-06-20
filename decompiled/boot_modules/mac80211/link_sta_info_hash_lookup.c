unsigned __int64 __fastcall link_sta_info_hash_lookup(__int64 a1, const void *a2)
{
  return rhltable_lookup((__int64 *)(a1 + 1792), a2, (__int64)&link_sta_rht_params);
}
