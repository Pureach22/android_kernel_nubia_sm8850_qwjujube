__int64 __fastcall ieee80211_change_iface(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v5; // x21
  __int64 result; // x0
  int v9; // w8
  char v10; // w10
  __int64 v11; // x0

  v5 = *(_QWORD *)(a2 + 4304);
  result = ieee80211_if_change_type(a2 + 2688, a3);
  if ( !(_DWORD)result )
  {
    if ( a3 == 2 )
    {
      v9 = *(_DWORD *)(a4 + 4);
      if ( (v9 & 0x80000000) == 0 )
      {
        if ( v9 == *(unsigned __int8 *)(a2 + 5212) )
          return 0;
        if ( *(_WORD *)(a2 + 8488) )
          return 4294967201LL;
        v10 = *(_BYTE *)(a2 + 5165);
        *(_BYTE *)(a2 + 5212) = v9;
        if ( (v10 & 8) == 0 )
          return 0;
        v11 = sta_info_get(a2 + 2688, a2 + 6840);
        if ( v11 )
          drv_sta_set_4addr(v5, a2 + 2688, v11 + 2688, *(_DWORD *)(a4 + 4) != 0);
        if ( *(_DWORD *)(a4 + 4) )
          ieee80211_send_4addr_nullfunc(v5, a2 + 2688);
      }
    }
    else if ( a3 == 4 && !*(_DWORD *)(a4 + 4) )
    {
      *(_QWORD *)(a2 + 4968) = 0;
      ieee80211_check_fast_rx_iface(a2 + 2688);
    }
    if ( *(_DWORD *)(a2 + 7408) != 6 )
      return 0;
    result = ieee80211_set_mon_options(a2 + 2688, a4);
    if ( !(_DWORD)result )
      return 0;
  }
  return result;
}
