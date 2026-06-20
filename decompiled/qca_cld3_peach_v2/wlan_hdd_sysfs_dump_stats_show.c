__int64 __fastcall wlan_hdd_sysfs_dump_stats_show(__int64 a1)
{
  int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 *v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v39[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = nullptr;
  v2 = _osif_vdev_sync_op_start(a1 - 1376, v39, (__int64)"wlan_hdd_sysfs_dump_stats_show");
  if ( !v2 )
  {
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__wlan_hdd_sysfs_dump_stats_show",
                         v3,
                         v4,
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         v10) )
    {
LABEL_4:
      v11 = -22;
LABEL_9:
      _osif_vdev_sync_op_stop((__int64)v39[0], (__int64)"wlan_hdd_sysfs_dump_stats_show");
      goto LABEL_10;
    }
    v20 = *(_QWORD *)(a1 + 1336);
    v21 = _wlan_hdd_validate_context(
            v20,
            (__int64)"__wlan_hdd_sysfs_dump_stats_show",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19);
    if ( !v21 )
    {
      if ( !wlan_hdd_validate_modules_state(v20, v22, v23, v24, v25, v26, v27, v28, v29) )
        goto LABEL_4;
      v21 = hdd_wlan_dump_stats(a1 + 1312, stats_id, v30, v31, v32, v33, v34, v35, v36, v37);
    }
    v11 = v21;
    goto LABEL_9;
  }
  v11 = v2;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v11;
}
