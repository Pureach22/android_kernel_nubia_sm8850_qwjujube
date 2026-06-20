__int64 __fastcall hdd_cp_stats_cstats_log_sap_go_dfs_event(__int64 a1, int a2)
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
  __int64 v13; // x19
  __int16 v14; // w8
  __int64 result; // x0
  int v16; // w9
  char v17; // w10
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int64 StatusReg; // x9
  __int16 v27; // w8
  char v28; // w10
  __int64 v29; // x8
  int v30; // w10
  __int64 v31; // x0
  _BYTE v32[30]; // [xsp+8h] [xbp-28h] BYREF
  __int16 v33; // [xsp+26h] [xbp-Ah]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v32, 0, sizeof(v32));
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_cp_stats_cstats_log_sap_go_dfs_event");
  if ( !vdev_by_user )
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
               "hdd_cp_stats_cstats_log_sap_go_dfs_event");
    goto LABEL_17;
  }
  v13 = vdev_by_user;
  if ( a2 > 15 )
  {
    if ( a2 == 16 )
    {
      v14 = 24;
      goto LABEL_13;
    }
    if ( a2 == 17 )
    {
      v14 = 26;
      goto LABEL_13;
    }
LABEL_10:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid Event",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_cp_stats_cstats_log_sap_go_dfs_event");
    result = _hdd_objmgr_put_vdev_by_user(v13, 5, "hdd_cp_stats_cstats_log_sap_go_dfs_event");
    goto LABEL_17;
  }
  if ( a2 == 14 )
  {
    v14 = 23;
    goto LABEL_13;
  }
  if ( a2 != 15 )
    goto LABEL_10;
  v14 = 25;
LABEL_13:
  v16 = *(_DWORD *)(vdev_by_user + 16);
  v17 = *(_BYTE *)(vdev_by_user + 168);
  *(_WORD *)v32 = v14;
  *(_WORD *)&v32[2] = 28;
  v32[4] = v16;
  v32[5] = v17;
  *(_QWORD *)&v32[6] = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v27 = *(_WORD *)(a1 + 713);
  *(_QWORD *)&v32[14] = StatusReg;
  v28 = *(_BYTE *)(a1 + 712);
  LOBYTE(StatusReg) = *(_BYTE *)(a1 + 717);
  *(_WORD *)&v32[23] = v27;
  v29 = *(_QWORD *)(v13 + 216);
  v32[22] = v28;
  v30 = *(_DWORD *)(a1 + 2424);
  v32[25] = StatusReg;
  v33 = v30;
  if ( v29 )
    v31 = *(_QWORD *)(v29 + 80);
  else
    v31 = 0;
  wlan_reg_get_cc_and_src(v31, &v32[26], v18, v19, v20, v21, v22, v23, v24, v25);
  _hdd_objmgr_put_vdev_by_user(v13, 5, "hdd_cp_stats_cstats_log_sap_go_dfs_event");
  result = wlan_cp_stats_cstats_write_to_buff(0, v32, 32);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
