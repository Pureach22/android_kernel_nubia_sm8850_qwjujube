__int64 __fastcall hdd_cp_stats_cstats_sap_go_start_event(__int64 a1, __int64 a2)
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
  size_t v18; // x2
  int v19; // w10
  char v20; // w10
  __int16 v21; // w9
  __int64 result; // x0
  int v23; // [xsp+4h] [xbp-4Ch] BYREF
  char v24; // [xsp+8h] [xbp-48h]
  char v25; // [xsp+9h] [xbp-47h]
  unsigned __int64 time_of_the_day_us; // [xsp+Ah] [xbp-46h]
  unsigned __int64 v27; // [xsp+12h] [xbp-3Eh]
  char v28; // [xsp+1Ah] [xbp-36h]
  __int16 v29; // [xsp+1Bh] [xbp-35h]
  char v30; // [xsp+1Dh] [xbp-33h]
  __int16 v31; // [xsp+1Eh] [xbp-32h]
  char v32; // [xsp+20h] [xbp-30h]
  _BYTE v33[47]; // [xsp+21h] [xbp-2Fh] BYREF

  *(_QWORD *)&v33[39] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v33, 0, 37);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_cp_stats_cstats_sap_go_start_event");
  if ( vdev_by_user )
  {
    v13 = *(_DWORD *)(vdev_by_user + 16);
    v14 = *(_BYTE *)(a2 + 22);
    v15 = vdev_by_user;
    v23 = 4063253;
    v24 = v13;
    v25 = v14;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v17 = *(_BYTE *)(a2 + 8);
    v27 = StatusReg;
    v18 = *(unsigned __int8 *)(a1 + 280);
    v28 = v17;
    LODWORD(StatusReg) = *(_DWORD *)(a2 + 12);
    v19 = *(_DWORD *)(a2 + 16);
    v32 = v18;
    v29 = StatusReg;
    LOWORD(StatusReg) = *(_WORD *)(a2 + 20);
    v30 = v19;
    v31 = StatusReg;
    qdf_mem_copy(v33, (const void *)(a1 + 281), v18);
    v20 = *(_BYTE *)(a1 + 717);
    v21 = *(_WORD *)(a1 + 713);
    v33[33] = *(_BYTE *)(a1 + 712);
    *(_WORD *)&v33[34] = v21;
    v33[36] = v20;
    _hdd_objmgr_put_vdev_by_user(v15, 5, "hdd_cp_stats_cstats_sap_go_start_event");
    result = wlan_cp_stats_cstats_write_to_buff(0, &v23, 66);
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
               "hdd_cp_stats_cstats_sap_go_start_event");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
