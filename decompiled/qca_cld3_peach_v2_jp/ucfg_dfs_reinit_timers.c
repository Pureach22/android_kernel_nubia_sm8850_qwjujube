__int64 __fastcall ucfg_dfs_reinit_timers(__int64 a1)
{
  __int64 dfs_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( (tgt_dfs_is_5ghz_supported_in_pdev(a1) & 1) != 0 )
  {
    dfs_obj = wlan_pdev_get_dfs_obj(a1);
    if ( !dfs_obj )
    {
      qdf_trace_msg(
        0x27u,
        2u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "ucfg_dfs_reinit_timers");
      return 16;
    }
    dfs_reinit_timers(dfs_obj);
  }
  return 0;
}
