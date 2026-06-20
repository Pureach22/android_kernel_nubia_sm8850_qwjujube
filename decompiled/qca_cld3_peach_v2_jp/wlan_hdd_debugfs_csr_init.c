__int64 __fastcall wlan_hdd_debugfs_csr_init(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x2
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v1 = result + 49152;
  v2 = result;
  if ( *(_QWORD *)(result + 52392)
    || (v3 = *(_QWORD *)(result + 52048),
        *(_DWORD *)(result + 52376) = 1,
        strcpy((char *)(result + 52352), "offload_info"),
        *(_QWORD *)(result + 52384) = 4096,
        result = debugfs_create_file(result + 52352, 292, v3, result + 52352, &fops_csr_debugfs),
        (*(_QWORD *)(v1 + 3240) = result) != 0) )
  {
    if ( *(_QWORD *)(v1 + 3192) )
      return result;
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Failed to create generic_info debugfs file",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wlan_hdd_debugfs_csr_init");
    if ( *(_QWORD *)(v1 + 3192) )
      return result;
  }
  v12 = *(_QWORD *)(v1 + 2896);
  *(_DWORD *)(v1 + 3176) = 0;
  strcpy((char *)(v2 + 52304), "roam_stats");
  *(_QWORD *)(v1 + 3184) = 4096;
  result = debugfs_create_file(v2 + 52304, 292, v12, v2 + 52304, &fops_csr_debugfs);
  *(_QWORD *)(v1 + 3192) = result;
  if ( !result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to create generic_info debugfs file",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wlan_hdd_debugfs_csr_init");
  return result;
}
