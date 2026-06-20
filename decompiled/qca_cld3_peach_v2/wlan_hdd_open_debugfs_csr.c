__int64 __fastcall wlan_hdd_open_debugfs_csr(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w19
  __int64 v25; // x0
  __int64 v26; // x20
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  __int64 *v37[2]; // [xsp+0h] [xbp-10h] BYREF

  v37[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 696);
  v37[0] = nullptr;
  v4 = v3 - 48LL * *(unsigned int *)(v3 + 24);
  result = _osif_vdev_sync_op_start(*(_QWORD *)(v4 - 52272), v37, (__int64)"wlan_hdd_open_debugfs_csr");
  if ( !(_DWORD)result )
  {
    v6 = v4 - 52304;
    hdd_debugfs_thread_increment();
    qdf_trace_msg(0x33u, 8u, "%s: enter", v7, v8, v9, v10, v11, v12, v13, v14, "__wlan_hdd_open_debugfs_csr");
    if ( *(_DWORD *)(v4 - 52304) == 1885692259 )
    {
      if ( (unsigned int)_wlan_hdd_validate_context(
                           *(_QWORD *)(v4 - 52280),
                           (__int64)"__wlan_hdd_open_debugfs_csr",
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22) )
      {
LABEL_8:
        v24 = -22;
        goto LABEL_9;
      }
      if ( (*(_QWORD *)(v4 - 50680) & 4) != 0 )
      {
        v25 = _qdf_mem_malloc(0x28u, "__wlan_hdd_open_debugfs_csr", 205);
        if ( v25 )
        {
          v26 = v25;
          v27 = _qdf_mem_malloc(*(_QWORD *)(v3 + 32), "__wlan_hdd_open_debugfs_csr", 209);
          *(_QWORD *)(v26 + 24) = v27;
          if ( v27 )
          {
            *(_QWORD *)v26 = 0;
            *(_QWORD *)(v26 + 8) = *(_QWORD *)(v3 + 32);
            v36 = *(_DWORD *)(v3 + 24);
            *(_QWORD *)(v26 + 32) = v6;
            *(_DWORD *)(v26 + 16) = v36;
            *(_QWORD *)(a2 + 32) = v26;
            qdf_trace_msg(0x33u, 8u, "%s: exit", v28, v29, v30, v31, v32, v33, v34, v35, "__wlan_hdd_open_debugfs_csr");
            v24 = 0;
            goto LABEL_10;
          }
          _qdf_mem_free(v26);
        }
        v24 = -12;
LABEL_9:
        hdd_debugfs_thread_decrement();
LABEL_10:
        _osif_vdev_sync_op_stop((__int64)v37[0], (__int64)"wlan_hdd_open_debugfs_csr");
        result = v24;
        goto LABEL_11;
      }
      v23 = "%s: Interface is not enabled";
    }
    else
    {
      v23 = "%s: Invalid adapter or adapter has invalid magic";
    }
    qdf_trace_msg(0x33u, 2u, v23, v15, v16, v17, v18, v19, v20, v21, v22, "__wlan_hdd_open_debugfs_csr");
    goto LABEL_8;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
