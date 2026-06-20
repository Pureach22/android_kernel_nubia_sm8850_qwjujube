__int64 __fastcall hdd_sysfs_gtx_bw_mask_show(__int64 a1, __int64 a2, __int64 a3)
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
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int command; // w20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x20
  __int64 *v60[2]; // [xsp+0h] [xbp-10h] BYREF

  v60[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v60[0] = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, v60, (__int64)"hdd_sysfs_gtx_bw_mask_show");
  if ( !v5 )
  {
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_gtx_bw_mask_show",
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
      _osif_vdev_sync_op_stop((__int64)v60[0], (__int64)"hdd_sysfs_gtx_bw_mask_show");
      goto LABEL_8;
    }
    v23 = *(_QWORD *)(a1 + 1336);
    v24 = _wlan_hdd_validate_context(
            v23,
            (__int64)"__hdd_sysfs_gtx_bw_mask_show",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( !v24 )
    {
      if ( !wlan_hdd_validate_modules_state(v23, v25, v26, v27, v28, v29, v30, v31, v32) )
        goto LABEL_4;
      command = wma_cli_get_command(
                  *(unsigned __int8 *)(*(_QWORD *)(a1 + 54144) + 8LL),
                  7,
                  7,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %s %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "hdd_sysfs_get_green_tx_param",
        "wmi_vdev_param_gtx_bw_mask",
        command);
      if ( (command & 0x80000000) != 0 )
      {
        v59 = jiffies;
        if ( _hdd_sysfs_gtx_bw_mask_show___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: failed to get green tx BW Mask",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "__hdd_sysfs_gtx_bw_mask_show");
          _hdd_sysfs_gtx_bw_mask_show___last_ticks = v59;
        }
        goto LABEL_4;
      }
      scnprintf(a3, 4096, "%d", command);
    }
    v14 = v24;
    goto LABEL_7;
  }
  v14 = v5;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v14;
}
