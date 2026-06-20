__int64 __fastcall hdd_sysfs_dp_traffic_end_indication_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 vdev_by_user; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x21
  int v43; // w22
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 *v61; // [xsp+8h] [xbp-18h] BYREF
  __int16 v62; // [xsp+14h] [xbp-Ch] BYREF
  unsigned __int8 v63; // [xsp+16h] [xbp-Ah]
  __int64 v64; // [xsp+18h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, &v61, (__int64)"hdd_sysfs_dp_traffic_end_indication_show");
  if ( !v5 )
  {
    v63 = 0;
    v62 = 0;
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_dp_traffic_end_indication_show",
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13) )
    {
LABEL_4:
      v14 = -22;
LABEL_7:
      _osif_vdev_sync_op_stop((__int64)v61, (__int64)"hdd_sysfs_dp_traffic_end_indication_show");
      goto LABEL_8;
    }
    v23 = _wlan_hdd_validate_context(
            *(_QWORD *)(a1 + 1336),
            (__int64)"__hdd_sysfs_dp_traffic_end_indication_show",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( !v23 )
    {
      if ( !wlan_hdd_validate_modules_state(*(_QWORD *)(a1 + 1336), v24, v25, v26, v27, v28, v29, v30, v31) )
        goto LABEL_4;
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                       *(_QWORD *)(a1 + 54136),
                       0x61u,
                       (__int64)"__hdd_sysfs_dp_traffic_end_indication_show");
      if ( !vdev_by_user )
        goto LABEL_4;
      v42 = vdev_by_user;
      v43 = ucfg_dp_traffic_end_indication_get(vdev_by_user, &v62, v34, v35, v36, v37, v38, v39, v40, v41);
      _hdd_objmgr_put_vdev_by_user(
        v42,
        0x61u,
        (__int64)"__hdd_sysfs_dp_traffic_end_indication_show",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52);
      if ( v43 )
        goto LABEL_4;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev_id:%u traffic end indication:%u defdscp:%u spldscp:%u",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "__hdd_sysfs_dp_traffic_end_indication_show",
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 54136) + 8LL),
        (unsigned __int8)v62,
        HIBYTE(v62),
        v63);
      scnprintf(a3, 4096, "%u %u %u\n", (unsigned __int8)v62, HIBYTE(v62), HIBYTE(v62));
    }
    v14 = v23;
    goto LABEL_7;
  }
  v14 = v5;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v14;
}
