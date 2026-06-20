__int64 __fastcall wlan_send_tx_complete_event(__int64 a1, __int64 a2, __int64 a3, char a4, int a5)
{
  __int64 v10; // x1
  __int64 result; // x0
  int v12; // w8
  unsigned __int16 *v13; // x23
  int v14; // w9
  int v15; // w22
  int v16; // w8
  __int64 v17; // x25
  __int64 v18; // x8
  unsigned int v19; // w9
  int v20; // w10
  unsigned int v21; // w21
  unsigned int v22; // w24
  __int64 v23; // x8
  int v24; // w2
  __int64 v25; // x20
  unsigned int v26; // w19
  int v27; // w7
  int v28; // w3
  int v29; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a3 + 10);
  v29 = 0;
  result = pe_find_session_by_vdev_id(a1, v10);
  if ( !result || *(_DWORD *)(result + 7036) )
    goto LABEL_35;
  v12 = (*(_BYTE *)(a2 + 68) & 4) != 0 ? *(unsigned __int16 *)(a2 + 66) : 0;
  if ( (unsigned int)(*(_DWORD *)(a2 + 112) + v12) < 0x1A )
    goto LABEL_35;
  v13 = *(unsigned __int16 **)(a2 + 224);
  if ( a4 == 1 )
    v14 = 2;
  else
    v14 = 3;
  if ( a4 )
    v15 = v14;
  else
    v15 = 1;
  if ( *(_BYTE *)(a3 + 56) )
  {
    v29 = *(char *)(a3 + 56);
    if ( a5 == 2 )
      goto LABEL_15;
LABEL_18:
    if ( (a5 & 0xFFFFFFFD) == 9 )
    {
      v18 = *(_QWORD *)(a2 + 224);
      if ( (*(_BYTE *)(v18 + 1) & 0x40) != 0 )
        v19 = 32;
      else
        v19 = 24;
      if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
        v20 = *(unsigned __int16 *)(a2 + 66);
      else
        v20 = 0;
      if ( *(_DWORD *)(a2 + 112) + v20 < (v19 | 2) )
        goto LABEL_35;
      v28 = *(unsigned __int16 *)(v18 + v19);
    }
    else
    {
      v28 = 0;
    }
    result = wlan_connectivity_mgmt_event(
               *(_QWORD *)(a1 + 21552),
               (int)v13,
               *(unsigned __int8 *)(a3 + 10),
               v28,
               v15,
               v29,
               0,
               0,
               0,
               0,
               a5);
    goto LABEL_35;
  }
  v17 = result;
  wlan_get_rssi_by_bssid(*(_QWORD *)(a1 + 21560), v13 + 8, &v29);
  result = v17;
  if ( a5 != 2 )
    goto LABEL_18;
LABEL_15:
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v16 = *(unsigned __int16 *)(a2 + 66);
  else
    v16 = 0;
  if ( (unsigned int)(*(_DWORD *)(a2 + 112) + v16) >= 0x1E )
  {
    v21 = v13[12];
    v22 = v13[13];
    v23 = *(_QWORD *)(a1 + 21552);
    v24 = *(unsigned __int8 *)(a3 + 10);
    v25 = result;
    v26 = v13[14];
    if ( v21 == 3 )
      v27 = v13[13];
    else
      v27 = 0;
    wlan_connectivity_mgmt_event(v23, (int)v13, v24, v26, v15, v29, v21, v27, v22, 0, 2);
    result = lim_cp_stats_cstats_log_auth_evt(v25, 0, v21, v22, v26);
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
