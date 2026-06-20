__int64 __fastcall os_if_cstats_log_nan_disc_enable_req_evt(unsigned __int8 a1, __int64 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w9
  char v13; // w10
  __int64 v14; // x20
  unsigned int *v15; // x8
  int v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  int v34; // [xsp+8h] [xbp-28h] BYREF
  char v35; // [xsp+Ch] [xbp-24h]
  char v36; // [xsp+Dh] [xbp-23h]
  unsigned __int64 time_of_the_day_us; // [xsp+Eh] [xbp-22h]
  unsigned __int64 StatusReg; // [xsp+16h] [xbp-1Ah]
  __int16 v39; // [xsp+1Eh] [xbp-12h]
  __int16 v40; // [xsp+20h] [xbp-10h]
  int v41; // [xsp+22h] [xbp-Eh]
  char v42; // [xsp+26h] [xbp-Ah]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a2 + 16), a1, 0x14u);
  if ( vdev_by_id_from_pdev )
  {
    v12 = *((_DWORD *)vdev_by_id_from_pdev + 4);
    v13 = *((_BYTE *)vdev_by_id_from_pdev + 104);
    v14 = (__int64)vdev_by_id_from_pdev;
    v34 = 1769501;
    v35 = v12;
    v36 = v13;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v16 = *(_DWORD *)(a2 + 8);
    v15 = (unsigned int *)*(unsigned int *)(a2 + 12);
    v41 = *(_DWORD *)(a2 + 28);
    v39 = v16;
    LOBYTE(v16) = *(_BYTE *)(a2 + 32);
    v40 = (__int16)v15;
    v42 = v16;
    wlan_objmgr_vdev_release_ref(v14, 0x14u, v15, v17, v18, v19, v20, v21, v22, v23, v24);
    result = wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v34, 0x1Fu, v25, v26, v27, v28, v29, v30, v31, v32);
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: vdev is null",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "os_if_cstats_log_nan_disc_enable_req_evt");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
