__int64 __fastcall wlan_hdd_release_mib_stats_debugfs(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 *v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 40);
  v30[0] = nullptr;
  v3 = *(_QWORD *)(v2 + 696);
  result = _osif_vdev_sync_op_start(v3, v30, (__int64)"wlan_hdd_release_mib_stats_debugfs");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "__wlan_hdd_release_mib_stats_debugfs",
      v3 + 296);
    v21 = _wlan_hdd_validate_context(
            *(_QWORD *)(v3 + 2712),
            (__int64)"__wlan_hdd_release_mib_stats_debugfs",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20);
    if ( !v21 )
    {
      qdf_mutex_acquire((__int64)&mibstats_lock);
      _qdf_mem_free(mib_stats_1);
      mib_stats_1 = 0;
      mib_stats_0 = 0;
      qdf_mutex_release((__int64)&mibstats_lock);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: exit",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__wlan_hdd_release_mib_stats_debugfs");
    }
    _osif_vdev_sync_op_stop((__int64)v30[0], (__int64)"wlan_hdd_release_mib_stats_debugfs");
    result = v21;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
