__int64 __fastcall ieee80211_set_cqm_rssi_config(__int64 a1, __int64 a2, int a3, int a4)
{
  bool v5; // zf
  __int64 v6; // x23
  __int64 v10; // x22
  __int64 v11; // x24
  int v12; // w25
  __int64 v13; // x1
  __int64 v14; // x8
  int v15; // w8

  if ( (*(_DWORD *)(a2 + 8560) & 3) == 1 )
    return 4294967201LL;
  if ( a3 )
    v5 = a4 == 0;
  else
    v5 = 1;
  v6 = a2 + 5165;
  v10 = 0;
  v11 = a2 + 7256;
  v12 = !v5;
  do
  {
    v13 = *(_QWORD *)(v11 + v10);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v13 + 944);
      if ( v14 )
      {
        if ( !v12 || *(_DWORD *)(v14 + 116) != a3 || *(_DWORD *)(v14 + 120) != a4 )
        {
          *(_DWORD *)(v14 + 116) = a3;
          *(_DWORD *)(v14 + 120) = a4;
          *(_QWORD *)(v14 + 124) = 0;
          *(_DWORD *)(v13 + 868) = 0;
          v15 = *(_DWORD *)(v13 + 8);
          if ( *(_WORD *)(v6 + 3323) )
          {
            if ( (((unsigned __int64)*(unsigned __int16 *)(v6 + 3325) >> v15) & 1) == 0 )
              goto LABEL_10;
          }
          else if ( v15 )
          {
            goto LABEL_10;
          }
          if ( (*(_BYTE *)v6 & 8) != 0 && (*(_BYTE *)(a2 + 8560) & 2) != 0 )
            ieee80211_link_info_change_notify(a2 + 2688, v13, 1024);
        }
      }
    }
LABEL_10:
    v10 += 8;
  }
  while ( v10 != 120 );
  return 0;
}
