__int64 __fastcall hdd_cp_stats_cstats_sap_go_stop_event(__int64 a1, __int64 a2)
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
  char v17; // w10
  __int16 v18; // w8
  char v19; // w10
  __int64 result; // x0
  int v21; // [xsp+Ch] [xbp-24h] BYREF
  char v22; // [xsp+10h] [xbp-20h]
  char v23; // [xsp+11h] [xbp-1Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-1Eh]
  unsigned __int64 v25; // [xsp+1Ah] [xbp-16h]
  char v26; // [xsp+22h] [xbp-Eh]
  char v27; // [xsp+23h] [xbp-Dh]
  __int16 v28; // [xsp+24h] [xbp-Ch]
  char v29; // [xsp+26h] [xbp-Ah]
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_cp_stats_cstats_sap_go_stop_event");
  if ( vdev_by_user )
  {
    v13 = *(_DWORD *)(vdev_by_user + 16);
    v14 = *(_BYTE *)(vdev_by_user + 104);
    v15 = vdev_by_user;
    v21 = 1507350;
    v22 = v13;
    v23 = v14;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v17 = *(_BYTE *)(a2 + 8);
    v25 = StatusReg;
    LOBYTE(StatusReg) = *(_BYTE *)(a1 + 712);
    v18 = *(_WORD *)(a1 + 713);
    v26 = v17;
    v19 = *(_BYTE *)(a1 + 717);
    v27 = StatusReg;
    v28 = v18;
    v29 = v19;
    _hdd_objmgr_put_vdev_by_user(v15, 5, "hdd_cp_stats_cstats_sap_go_stop_event");
    result = wlan_cp_stats_cstats_write_to_buff(0, &v21, 27);
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
               "hdd_cp_stats_cstats_sap_go_stop_event");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
