__int64 __fastcall wlan_hdd_read_debugfs_csr(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v7; // x24
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  const char *v27; // x2
  __int64 v28; // x21
  __int64 updated; // x4
  int v30; // w8
  __int64 v31; // x2
  __int64 v32; // x3
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
  __int64 *v49[2]; // [xsp+0h] [xbp-10h] BYREF

  v49[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 32);
  v49[0] = nullptr;
  LODWORD(result) = _osif_vdev_sync_op_start(
                      *(_QWORD *)(*(_QWORD *)(v7 + 32) + 32LL),
                      v49,
                      (__int64)"wlan_hdd_read_debugfs_csr");
  if ( !(_DWORD)result )
  {
    v17 = *(_QWORD *)(v7 + 32);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v9, v10, v11, v12, v13, v14, v15, v16, "__wlan_hdd_read_debugfs_csr");
    if ( *(_DWORD *)v17 == 1885692259 )
    {
      v26 = *(_QWORD *)(v17 + 24);
      if ( (unsigned int)_wlan_hdd_validate_context(
                           v26,
                           (__int64)"__wlan_hdd_read_debugfs_csr",
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           v25) )
      {
LABEL_9:
        v28 = 0;
LABEL_10:
        _osif_vdev_sync_op_stop((__int64)v49[0], (__int64)"wlan_hdd_read_debugfs_csr");
        result = v28;
        goto LABEL_11;
      }
      if ( (*(_QWORD *)(v17 + 1624) & 4) != 0 )
      {
        if ( *a4 )
        {
          updated = *(_QWORD *)v7;
        }
        else
        {
          v30 = *(_DWORD *)(v7 + 16);
          v31 = *(_QWORD *)(v7 + 24);
          v32 = *(_QWORD *)(v7 + 8);
          if ( v30 == 1 )
          {
            updated = wlan_hdd_debugfs_update_filters_info(v26, v17, v31, v32);
          }
          else if ( v30 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to fetch stats, unknown stats type",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "wlan_hdd_debugfs_update_csr");
            updated = 0;
          }
          else
          {
            updated = wlan_hdd_debugfs_update_roam_stats(v26, v17, v31, v32);
          }
          *(_QWORD *)v7 = updated;
        }
        v28 = simple_read_from_buffer(a2, a3, a4, *(_QWORD *)(v7 + 24), updated);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: length written = %zu, count: %zu, pos: %lld",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "__wlan_hdd_read_debugfs_csr");
        qdf_trace_msg(0x33u, 8u, "%s: exit", v41, v42, v43, v44, v45, v46, v47, v48, "__wlan_hdd_read_debugfs_csr");
        goto LABEL_10;
      }
      v27 = "%s: Interface is not enabled";
    }
    else
    {
      v27 = "%s: Invalid adapter or adapter has invalid magic";
    }
    qdf_trace_msg(0x33u, 2u, v27, v18, v19, v20, v21, v22, v23, v24, v25, "__wlan_hdd_read_debugfs_csr");
    goto LABEL_9;
  }
  result = (int)result;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
