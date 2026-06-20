__int64 __fastcall ucfg_dfs_set_precac_enable(__int64 a1)
{
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  if ( wlan_pdev_get_dfs_obj(a1) )
    return 0;
  qdf_trace_msg(
    0x27u,
    2u,
    "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs",
    v1,
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    "ucfg_dfs_set_precac_enable");
  return 16;
}
