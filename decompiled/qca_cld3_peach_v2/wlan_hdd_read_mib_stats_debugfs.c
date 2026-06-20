__int64 __fastcall wlan_hdd_read_mib_stats_debugfs(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v7; // x8
  __int64 v8; // x22
  int v9; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w0
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
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int mib_stats; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 *v78[2]; // [xsp+0h] [xbp-10h] BYREF

  v78[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 40);
  v78[0] = nullptr;
  v8 = *(_QWORD *)(v7 + 696);
  v9 = _osif_vdev_sync_op_start(v8, v78, (__int64)"wlan_hdd_read_mib_stats_debugfs");
  if ( !v9 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_read_mib_stats_debugfs",
      v8 + 296);
    v27 = _wlan_hdd_validate_context(
            *(_QWORD *)(v8 + 2712),
            (__int64)"__wlan_hdd_read_mib_stats_debugfs",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( v27 )
    {
      v18 = v27;
    }
    else
    {
      if ( *a4 || (mib_stats = wlan_hdd_get_mib_stats(v8 + 2688, v28, v29, v30, v31, v32, v33, v34, v35)) == 0 )
      {
        qdf_trace_msg(0x33u, 8u, "%s: enter", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_debugfs_mib_stats_update");
        qdf_mutex_acquire((__int64)&mibstats_lock);
        if ( mib_stats_1 )
        {
          v18 = simple_read_from_buffer(a2, a3, a4, mib_stats_1, mib_stats_0);
          qdf_mutex_release((__int64)&mibstats_lock);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: mib stats read req: count: %zu, pos: %lld",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "hdd_debugfs_mib_stats_update",
            a3,
            *a4);
          qdf_trace_msg(0x33u, 8u, "%s: exit", v52, v53, v54, v55, v56, v57, v58, v59, "hdd_debugfs_mib_stats_update");
        }
        else
        {
          qdf_mutex_release((__int64)&mibstats_lock);
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Trying to read from NULL buffer",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "hdd_debugfs_mib_stats_update");
          v18 = 0;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: %zu characters written into debugfs",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "__wlan_hdd_read_mib_stats_debugfs",
          v18);
        goto LABEL_13;
      }
      v18 = mib_stats;
    }
    qdf_mutex_acquire((__int64)&mibstats_lock);
    _qdf_mem_free(mib_stats_1);
    mib_stats_1 = 0;
    mib_stats_0 = 0;
    qdf_mutex_release((__int64)&mibstats_lock);
LABEL_13:
    qdf_trace_msg(0x33u, 8u, "%s: exit", v36, v37, v38, v39, v40, v41, v42, v43, "__wlan_hdd_read_mib_stats_debugfs");
    _osif_vdev_sync_op_stop((__int64)v78[0], (__int64)"wlan_hdd_read_mib_stats_debugfs");
    goto LABEL_14;
  }
  v18 = v9;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v18;
}
