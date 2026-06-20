__int64 __fastcall hdd_sysfs_range_ext_show(__int64 a1, __int64 a2, __int64 a3)
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
  __int64 v23; // x21
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int command; // w0
  __int64 *v51[2]; // [xsp+0h] [xbp-10h] BYREF

  v51[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, v51, (__int64)"hdd_sysfs_range_ext_show");
  if ( !v5 )
  {
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_range_ext_show",
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
LABEL_9:
      _osif_vdev_sync_op_stop((__int64)v51[0], (__int64)"hdd_sysfs_range_ext_show");
      goto LABEL_10;
    }
    v23 = *(_QWORD *)(a1 + 1336);
    v24 = _wlan_hdd_validate_context(v23, (__int64)"__hdd_sysfs_range_ext_show", v15, v16, v17, v18, v19, v20, v21, v22);
    if ( !v24 )
    {
      if ( !wlan_hdd_validate_modules_state(v23, v25, v26, v27, v28, v29, v30, v31, v32) )
        goto LABEL_4;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: GET wmi_vdev_param_he_range_ext",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "__hdd_sysfs_range_ext_show");
      command = wma_cli_get_command(
                  *(unsigned __int8 *)(*(_QWORD *)(a1 + 54136) + 8LL),
                  107,
                  1,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48);
      scnprintf(a3, 4096, "%d\n", command);
    }
    v14 = v24;
    goto LABEL_9;
  }
  v14 = v5;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v14;
}
