__int64 __fastcall sta_info_hash_lookup(__int64 a1, __int64 a2)
{
  return rhltable_lookup(a1 + 1632, a2, &sta_rht_params);
}
