__int64 __fastcall tgt_dfs_control(
        __int64 a1,
        int a2,
        unsigned int *a3,
        unsigned int a4,
        __int64 a5,
        _DWORD *a6,
        _DWORD *a7)
{
  __int64 dfs_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( dfs_obj )
  {
    v22 = dfs_control(dfs_obj, a2, a3, a4, a5, a6, v14, v15, v16, v17, v18, v19, v20, v21);
    *a7 = v22;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tgt_dfs_control");
    return 16;
  }
}
