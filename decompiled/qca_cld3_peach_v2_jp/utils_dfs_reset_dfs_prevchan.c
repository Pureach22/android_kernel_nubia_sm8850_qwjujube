__int64 __fastcall utils_dfs_reset_dfs_prevchan(__int64 a1)
{
  __int64 result; // x0
  __int64 dfs_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = tgt_dfs_is_5ghz_supported_in_pdev(a1);
  if ( (result & 1) != 0 )
  {
    dfs_obj = wlan_pdev_get_dfs_obj(a1);
    if ( dfs_obj )
      return (__int64)dfs_reset_dfs_prevchan(dfs_obj);
    else
      return qdf_trace_msg(
               0x27u,
               2u,
               "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is null",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "utils_dfs_reset_dfs_prevchan");
  }
  return result;
}
