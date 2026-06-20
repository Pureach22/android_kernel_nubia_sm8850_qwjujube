unsigned __int64 __fastcall ieee80211_find_sta_by_link_addrs(__int64 a1, const void *a2, __int64 a3, _DWORD *a4)
{
  unsigned __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x10
  int v11; // w11
  int v12; // w10

  result = rhltable_lookup((__int64 *)(a1 + 1792), a2, (__int64)&link_sta_rht_params);
  if ( result )
  {
    while ( 1 )
    {
      v7 = *(_QWORD *)(result + 16);
      v8 = *(unsigned __int8 *)(result - 10);
      if ( !a3 )
        break;
      if ( (unsigned int)v8 >= 0x10 )
      {
        __break(0x5512u);
        return sta_info_get_by_addrs();
      }
      v9 = *(_QWORD *)(*(_QWORD *)(v7 + 80) + 8 * v8 + 4568);
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 944);
        v11 = *(_DWORD *)(v10 + 28);
        v12 = *(unsigned __int16 *)(v10 + 32);
        if ( v11 == *(_DWORD *)a3 && v12 == *(unsigned __int16 *)(a3 + 4) )
          break;
      }
      result = *(_QWORD *)(result + 8);
      if ( !result )
        return result;
    }
    if ( a4 )
      *a4 = v8;
    return v7 + 2688;
  }
  return result;
}
