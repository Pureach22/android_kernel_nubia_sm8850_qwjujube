__int64 __fastcall os_if_cstats_log_disable_nan_disc_evt(__int64 a1, unsigned __int8 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  int v11; // w9
  char v12; // w10
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  int v31; // [xsp+0h] [xbp-20h] BYREF
  char v32; // [xsp+4h] [xbp-1Ch]
  char v33; // [xsp+5h] [xbp-1Bh]
  unsigned __int64 time_of_the_day_us; // [xsp+6h] [xbp-1Ah]
  unsigned __int64 StatusReg; // [xsp+Eh] [xbp-12h]
  __int16 v36; // [xsp+16h] [xbp-Ah]
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x14u);
  if ( vdev_by_id_from_pdev )
  {
    v11 = *((_DWORD *)vdev_by_id_from_pdev + 4);
    v12 = *((_BYTE *)vdev_by_id_from_pdev + 104);
    v13 = (__int64)vdev_by_id_from_pdev;
    v31 = 1310751;
    v32 = v11;
    v33 = v12;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v36 = 257;
    wlan_objmgr_vdev_release_ref(
      v13,
      0x14u,
      (unsigned int *)((char *)&qword_FC + 5),
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21);
    result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v31, 0x18u, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: vdev is null",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "os_if_cstats_log_disable_nan_disc_evt");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
