__int64 __fastcall pmo_get_min_pagefault_wakeups_for_action(__int64 a1)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( result )
    return *(unsigned __int8 *)(result + 104);
  return result;
}
