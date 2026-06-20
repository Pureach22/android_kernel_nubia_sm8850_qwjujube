__int64 __fastcall wlan_hdd_open_mib_stats_debugfs(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x19
  unsigned int v45; // w19
  __int64 *v46[2]; // [xsp+0h] [xbp-10h] BYREF

  v46[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 696);
  v46[0] = nullptr;
  result = _osif_vdev_sync_op_start(v1, v46, (__int64)"wlan_hdd_open_mib_stats_debugfs");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "__wlan_hdd_open_mib_stats_debugfs",
      v1 + 296);
    v19 = _hdd_validate_adapter(
            v1 + 2688,
            (__int64)"__wlan_hdd_open_mib_stats_debugfs",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18);
    if ( v19 )
      goto LABEL_8;
    v19 = _wlan_hdd_validate_context(
            *(_QWORD *)(v1 + 2712),
            (__int64)"__wlan_hdd_open_mib_stats_debugfs",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27);
    if ( v19 )
      goto LABEL_8;
    qdf_mutex_acquire((__int64)&mibstats_lock);
    if ( mib_stats_1 )
    {
      qdf_mutex_release((__int64)&mibstats_lock);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Buffer is already allocated",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wlan_hdd_mibstats_alloc_buf");
    }
    else
    {
      mib_stats_0 = 0;
      v44 = _qdf_mem_malloc(0x1000u, "wlan_hdd_mibstats_alloc_buf", 104);
      mib_stats_1 = v44;
      qdf_mutex_release((__int64)&mibstats_lock);
      if ( !v44 )
      {
        v19 = -22;
        goto LABEL_8;
      }
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v36, v37, v38, v39, v40, v41, v42, v43, "__wlan_hdd_open_mib_stats_debugfs");
    v19 = 0;
LABEL_8:
    v45 = v19;
    _osif_vdev_sync_op_stop((__int64)v46[0], (__int64)"wlan_hdd_open_mib_stats_debugfs");
    result = v45;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
