__int64 __fastcall tgt_dfs_is_radar_enabled(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = wlan_pdev_get_dfs_obj(a1);
  if ( !result )
    return qdf_trace_msg(
             0x27u,
             2u,
             "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "tgt_dfs_is_radar_enabled");
  return result;
}
