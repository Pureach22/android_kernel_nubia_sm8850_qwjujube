__int64 __fastcall ieee80211_set_mon_options(__int64 a1, int *a2)
{
  int v2; // w8
  __int64 v3; // x19
  __int64 v5; // x20
  _QWORD *v6; // x8
  __int64 v7; // x21
  int *v8; // x22
  __int64 v9; // x0
  __int64 v10; // x8
  int *v11; // x9
  int v12; // w10
  bool v13; // w11
  _DWORD *v14; // x21
  __int64 v15; // x20

  v2 = *a2;
  v3 = *(_QWORD *)(a1 + 1616);
  if ( *a2 && (*(_QWORD *)(a1 + 1632) & 1) != 0 && ((*(_DWORD *)(a1 + 2264) ^ v2) & 0x60) != 0 )
    return 4294967280LL;
  v5 = *(_QWORD *)(v3 + 5384);
  if ( v5 )
  {
    if ( (*(_QWORD *)(v3 + 96) & 0x1000) != 0 )
    {
      v6 = *((_QWORD **)a2 + 2);
      v7 = a1;
      if ( v6 )
      {
        v8 = a2;
        v9 = *(_QWORD *)(v3 + 5384);
        *(_QWORD *)(v5 + 5008) = *v6;
        v10 = *(_QWORD *)(*((_QWORD *)a2 + 2) + 8LL);
        *(_QWORD *)(v5 + 5024) = *(_QWORD *)(*((_QWORD *)a2 + 2) + 16LL);
        *(_QWORD *)(v5 + 5016) = v10;
        ieee80211_link_info_change_notify(v9, v5 + 3616, 0x800000);
        a2 = v8;
        LOBYTE(v6) = **((_QWORD **)v8 + 2) != 0;
      }
      v11 = *((int **)a2 + 3);
      if ( v11 )
      {
        v12 = *v11;
        v13 = (*v11 & 1) == 0 && (v12 | *((unsigned __int16 *)v11 + 2)) != 0;
        *(_DWORD *)(v5 + 2268) = v12;
        a1 = v7;
        *(_WORD *)(v5 + 2272) = *((_WORD *)v11 + 2);
      }
      else
      {
        v13 = 0;
        a1 = v7;
      }
      *(_BYTE *)(v5 + 5639) = (unsigned __int8)v6 | v13;
      v2 = *a2;
    }
  }
  else if ( *((_QWORD *)a2 + 2) || *((_QWORD *)a2 + 3) )
  {
    return 4294967201LL;
  }
  if ( v2 )
  {
    if ( (*(_QWORD *)(a1 + 1632) & 1) != 0 )
    {
      v14 = a2;
      v15 = a1;
      ((void (*)(void))ieee80211_adjust_monitor_flags)();
      *(_DWORD *)(v15 + 2264) = *v14;
      ieee80211_adjust_monitor_flags(v15, 1);
      ieee80211_configure_filter(v3);
    }
    else
    {
      *(_DWORD *)(a1 + 2264) = v2;
    }
  }
  return 0;
}
