__int64 __fastcall hdd_sysfs_dp_tx_delay_stats_show(__int64 a1, __int64 a2, __int64 a3)
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
  __int64 v14; // x22
  _QWORD *context; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w0
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
  __int64 v49; // x8
  _DWORD *v50; // x8
  __int64 v51; // x1
  unsigned int v52; // w21
  __int64 *v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v54[0] = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, v54, (__int64)"hdd_sysfs_dp_tx_delay_stats_show");
  if ( !v5 )
  {
    context = _cds_get_context(71, (__int64)"__hdd_sysfs_dp_tx_delay_stats_show", v6, v7, v8, v9, v10, v11, v12, v13);
    v14 = -22;
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_dp_tx_delay_stats_show",
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23)
      || !context )
    {
      goto LABEL_17;
    }
    v32 = _wlan_hdd_validate_context(
            *(_QWORD *)(a1 + 1336),
            (__int64)"__hdd_sysfs_dp_tx_delay_stats_show",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31);
    if ( v32 )
      goto LABEL_16;
    if ( !wlan_hdd_validate_modules_state(*(_QWORD *)(a1 + 1336), v33, v34, v35, v36, v37, v38, v39, v40) )
    {
LABEL_17:
      _osif_vdev_sync_op_stop((__int64)v54[0], (__int64)"hdd_sysfs_dp_tx_delay_stats_show");
      goto LABEL_18;
    }
    if ( *context && (v49 = *(_QWORD *)(*context + 32LL)) != 0 )
    {
      v50 = *(_DWORD **)(v49 + 304);
      if ( v50 )
      {
        v51 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 54136) + 8LL);
        if ( *(v50 - 1) != -1653155309 )
          __break(0x8228u);
        v52 = ((unsigned __int8 (__fastcall *)(_QWORD *, __int64))v50)(context, v51);
        goto LABEL_15;
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "cdp_vdev_is_tx_delay_stats_enabled");
    }
    v52 = 0;
LABEL_15:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev_id: %d tx_delay_stats: %d",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "__hdd_sysfs_dp_tx_delay_stats_show",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 54136) + 8LL),
      v52);
    scnprintf(a3, 4096, "%d\n", v52);
LABEL_16:
    v14 = v32;
    goto LABEL_17;
  }
  v14 = v5;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v14;
}
