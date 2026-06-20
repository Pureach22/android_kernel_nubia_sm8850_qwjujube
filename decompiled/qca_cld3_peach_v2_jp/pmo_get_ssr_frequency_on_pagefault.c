__int64 __fastcall pmo_get_ssr_frequency_on_pagefault(__int64 a1)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( result )
    return *(unsigned int *)(result + 112);
  return result;
}
