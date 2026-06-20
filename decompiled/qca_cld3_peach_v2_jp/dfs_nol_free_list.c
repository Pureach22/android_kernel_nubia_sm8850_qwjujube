__int64 __fastcall dfs_nol_free_list(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w8

  v1 = *(_QWORD *)(result + 64);
  v2 = result;
  while ( v1 )
  {
    v3 = v1;
    v1 = *(_QWORD *)(v1 + 136);
    result = _qdf_mem_free(v3);
    v12 = *(_DWORD *)(v2 + 84) - 1;
    *(_DWORD *)(v2 + 84) = v12;
    if ( v12 < 0 )
      result = qdf_trace_msg(
                 0x27u,
                 2u,
                 "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_nol_count < 0",
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 "dfs_nol_free_list");
  }
  *(_QWORD *)(v2 + 64) = 0;
  return result;
}
