__int64 __fastcall hdd_cp_stats_cstats_log_sap_go_sta_assoc_reassoc_event(__int64 a1, __int64 a2)
{
  __int64 vdev_by_user; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w9
  char v14; // w10
  __int64 v15; // x21
  int v16; // w9
  char v17; // w8
  char v18; // w8
  char v19; // w8
  __int64 result; // x0
  int v21; // [xsp+4h] [xbp-2Ch] BYREF
  char v22; // [xsp+8h] [xbp-28h]
  char v23; // [xsp+9h] [xbp-27h]
  unsigned __int64 time_of_the_day_us; // [xsp+Ah] [xbp-26h]
  unsigned __int64 StatusReg; // [xsp+12h] [xbp-1Eh]
  char v26; // [xsp+1Ah] [xbp-16h]
  __int16 v27; // [xsp+1Bh] [xbp-15h]
  char v28; // [xsp+1Dh] [xbp-13h]
  __int16 v29; // [xsp+1Eh] [xbp-12h]
  char v30; // [xsp+20h] [xbp-10h]
  char v31; // [xsp+21h] [xbp-Fh]
  __int16 v32; // [xsp+22h] [xbp-Eh]
  int v33; // [xsp+24h] [xbp-Ch]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_cp_stats_cstats_log_sap_go_sta_assoc_reassoc_event");
  if ( vdev_by_user )
  {
    v13 = *(_DWORD *)(vdev_by_user + 16);
    v14 = *(_BYTE *)(vdev_by_user + 104);
    v15 = vdev_by_user;
    v21 = 2097180;
    v22 = v13;
    v23 = v14;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    _hdd_objmgr_put_vdev_by_user(v15, 5, "hdd_cp_stats_cstats_log_sap_go_sta_assoc_reassoc_event");
    v16 = *(_DWORD *)(a2 + 36);
    v32 = *(_WORD *)(a2 + 20);
    v17 = *(_BYTE *)(a2 + 8);
    v33 = v16;
    LOWORD(v16) = *(_WORD *)(a2 + 9);
    v26 = v17;
    v18 = *(_BYTE *)(a2 + 13);
    v27 = v16;
    LOWORD(v16) = *(_WORD *)(a1 + 712);
    v28 = v18;
    v19 = *(_BYTE *)(a1 + 714);
    v29 = v16;
    LOBYTE(v16) = *(_BYTE *)(a1 + 717);
    v30 = v19;
    v31 = v16;
    result = wlan_cp_stats_cstats_write_to_buff(0, &v21, 36);
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: vdev is NULL",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "hdd_cp_stats_cstats_log_sap_go_sta_assoc_reassoc_event");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
