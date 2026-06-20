unsigned __int64 __fastcall ieee80211_find_sta_by_ifaddr(__int64 a1, const void *a2, __int64 a3)
{
  unsigned __int64 result; // x0
  unsigned __int64 v5; // x9

  result = rhltable_lookup((__int64 *)(a1 + 1632), a2, (__int64)&sta_rht_params);
  if ( result )
  {
    v5 = result;
    while ( a3 )
    {
      if ( !(*(_DWORD *)a3 ^ *(_DWORD *)(*(_QWORD *)(v5 + 32) + 5842LL)
           | *(unsigned __int16 *)(a3 + 4) ^ *(unsigned __int16 *)(*(_QWORD *)(v5 + 32) + 5846LL)) )
      {
        result = v5;
        break;
      }
      v5 = *(_QWORD *)(v5 + 8);
      if ( !v5 )
        return 0;
    }
    if ( *(_BYTE *)(result + 156) )
      result += 2640LL;
    else
      return 0;
  }
  return result;
}
