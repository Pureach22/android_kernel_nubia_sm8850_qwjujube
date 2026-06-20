__int64 __fastcall hdd_cp_stats_cstats_log_sap_go_sta_disassoc_event(__int64 a1, __int64 a2)
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
  unsigned __int64 StatusReg; // x9
  __int16 v17; // w10
  __int16 v18; // w8
  int v19; // w11
  int v20; // w10
  __int64 result; // x0
  int v22; // [xsp+Ch] [xbp-34h] BYREF
  char v23; // [xsp+10h] [xbp-30h]
  char v24; // [xsp+11h] [xbp-2Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-2Eh]
  unsigned __int64 v26; // [xsp+1Ah] [xbp-26h]
  char v27; // [xsp+22h] [xbp-1Eh]
  __int16 v28; // [xsp+23h] [xbp-1Dh]
  char v29; // [xsp+25h] [xbp-1Bh]
  char v30; // [xsp+26h] [xbp-1Ah]
  __int16 v31; // [xsp+27h] [xbp-19h]
  char v32; // [xsp+29h] [xbp-17h]
  __int16 v33; // [xsp+2Ah] [xbp-16h]
  int v34; // [xsp+2Ch] [xbp-14h]
  char v35; // [xsp+30h] [xbp-10h]
  int v36; // [xsp+31h] [xbp-Fh]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_cp_stats_cstats_log_sap_go_sta_disassoc_event");
  if ( vdev_by_user )
  {
    v13 = *(_DWORD *)(vdev_by_user + 16);
    v14 = *(_BYTE *)(vdev_by_user + 168);
    v15 = vdev_by_user;
    v22 = 2424859;
    v23 = v13;
    v24 = v14;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v17 = *(_WORD *)(a2 + 14);
    v26 = StatusReg;
    v18 = *(_WORD *)(a1 + 713);
    v19 = *(_DWORD *)(a2 + 24);
    v33 = v17;
    LODWORD(StatusReg) = *(_DWORD *)(a2 + 16);
    v20 = *(_DWORD *)(a2 + 20);
    v31 = v18;
    LOBYTE(v18) = *(_BYTE *)(a2 + 8);
    v35 = v19;
    v34 = StatusReg;
    LOBYTE(StatusReg) = *(_BYTE *)(a1 + 712);
    v27 = v18;
    LOBYTE(v18) = *(_BYTE *)(a2 + 13);
    v30 = StatusReg;
    LOBYTE(StatusReg) = *(_BYTE *)(a1 + 717);
    v36 = v20;
    v32 = StatusReg;
    LOWORD(StatusReg) = *(_WORD *)(a2 + 9);
    v29 = v18;
    v28 = StatusReg;
    _hdd_objmgr_put_vdev_by_user(v15, 5, "hdd_cp_stats_cstats_log_sap_go_sta_disassoc_event");
    result = wlan_cp_stats_cstats_write_to_buff(0, &v22, 41);
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
               "hdd_cp_stats_cstats_log_sap_go_sta_disassoc_event");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
