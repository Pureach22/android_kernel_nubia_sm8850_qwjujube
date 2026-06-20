__int64 __fastcall ieee80211_set_cqm_rssi_range_config(__int64 a1, __int64 a2, int a3, int a4)
{
  _BYTE *v5; // x23
  __int64 v8; // x22
  __int64 v9; // x24
  _WORD *v10; // x25
  unsigned __int16 *v11; // x26
  __int64 v12; // x1
  __int64 v13; // x8
  int v14; // w8

  if ( (*(_BYTE *)(a2 + 8560) & 1) != 0 )
    return 4294967201LL;
  v5 = (_BYTE *)(a2 + 5165);
  v8 = 0;
  v9 = a2 + 7256;
  v10 = (_WORD *)(a2 + 8488);
  v11 = (unsigned __int16 *)(a2 + 8490);
  do
  {
    v12 = *(_QWORD *)(v9 + v8);
    if ( v12 )
    {
      v13 = *(_QWORD *)(v12 + 944);
      if ( v13 )
      {
        *(_QWORD *)(v13 + 116) = 0;
        *(_DWORD *)(v13 + 124) = a3;
        *(_DWORD *)(v13 + 128) = a4;
        *(_DWORD *)(v12 + 868) = 0;
        v14 = *(_DWORD *)(v12 + 8);
        if ( *v10 )
        {
          if ( (((unsigned __int64)*v11 >> v14) & 1) == 0 )
            goto LABEL_4;
        }
        else if ( v14 )
        {
          goto LABEL_4;
        }
        if ( (*v5 & 8) != 0 && (*(_BYTE *)(a2 + 8560) & 2) != 0 )
          ieee80211_link_info_change_notify(a2 + 2688, v12, 1024);
      }
    }
LABEL_4:
    v8 += 8;
  }
  while ( v8 != 120 );
  return 0;
}
