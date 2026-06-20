__int64 __fastcall wlan_hdd_release_debugfs_csr(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 32);
  v22[0] = nullptr;
  result = _osif_vdev_sync_op_start(
             *(_QWORD *)(*(_QWORD *)(v3 + 32) + 32LL),
             v22,
             (__int64)"wlan_hdd_release_debugfs_csr");
  if ( !(_DWORD)result )
  {
    v13 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v5, v6, v7, v8, v9, v10, v11, v12, "__wlan_hdd_release_debugfs_csr");
    *(_QWORD *)(a2 + 32) = 0;
    _qdf_mem_free(*(_QWORD *)(v13 + 24));
    _qdf_mem_free(v13);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v14, v15, v16, v17, v18, v19, v20, v21, "__wlan_hdd_release_debugfs_csr");
    hdd_debugfs_thread_decrement();
    _osif_vdev_sync_op_stop((__int64)v22[0], (__int64)"wlan_hdd_release_debugfs_csr");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
