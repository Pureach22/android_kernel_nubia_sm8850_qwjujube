__int64 __fastcall wcnss_debugfs_open(__int64 a1)
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
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 *v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 696);
  v28[0] = nullptr;
  result = _osif_vdev_sync_op_start(v1, v28, (__int64)"wcnss_debugfs_open");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v3, v4, v5, v6, v7, v8, v9, v10, "__wcnss_debugfs_open");
    if ( *(_DWORD *)(v1 + 2688) == 1885692259 )
    {
      v19 = _wlan_hdd_validate_context(
              *(_QWORD *)(v1 + 2712),
              (__int64)"__wcnss_debugfs_open",
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "__wcnss_debugfs_open");
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid adapter or adapter has invalid magic",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__wcnss_debugfs_open");
      v19 = -22;
    }
    _osif_vdev_sync_op_stop((__int64)v28[0], (__int64)"wcnss_debugfs_open");
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
