__int64 __fastcall wlan_hdd_open_ll_stats_debugfs(__int64 a1)
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
  int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  int v29; // w20
  unsigned int v30; // w19
  __int64 *v31[2]; // [xsp+0h] [xbp-10h] BYREF

  v31[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 696);
  v31[0] = nullptr;
  result = _osif_vdev_sync_op_start(v1, v31, (__int64)"wlan_hdd_open_ll_stats_debugfs");
  if ( !(_DWORD)result )
  {
    v11 = _hdd_validate_adapter(v1 + 2688, (__int64)"__wlan_hdd_open_ll_stats_debugfs", v3, v4, v5, v6, v7, v8, v9, v10);
    if ( !v11 )
    {
      v11 = _wlan_hdd_validate_context(
              *(_QWORD *)(v1 + 2712),
              (__int64)"__wlan_hdd_open_ll_stats_debugfs",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19);
      if ( !v11 )
      {
        mutex_lock(&llstats_mutex);
        if ( ll_stats_1 )
        {
          mutex_unlock(&llstats_mutex);
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Buffer is already allocated",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "wlan_hdd_llstats_alloc_buf");
          goto LABEL_7;
        }
        ll_stats_0 = 0;
        v28 = _qdf_mem_malloc(0x8000u, "wlan_hdd_llstats_alloc_buf", 349);
        ll_stats_1 = v28;
        mutex_unlock(&llstats_mutex);
        if ( v28 )
        {
LABEL_7:
          v11 = wlan_hdd_ll_stats_get(*(_QWORD *)(v1 + 55520), 0xFFFFFFFF, 7u);
          if ( v11 )
          {
            v29 = v11;
            mutex_lock(&llstats_mutex);
            _qdf_mem_free(ll_stats_1);
            ll_stats_1 = 0;
            ll_stats_0 = 0;
            mutex_unlock(&llstats_mutex);
            v11 = v29;
          }
          goto LABEL_10;
        }
        v11 = -22;
      }
    }
LABEL_10:
    v30 = v11;
    _osif_vdev_sync_op_stop((__int64)v31[0], (__int64)"wlan_hdd_open_ll_stats_debugfs");
    result = v30;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
