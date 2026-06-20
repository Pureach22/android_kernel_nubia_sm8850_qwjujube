__int64 __fastcall tgt_dfs_is_precac_timer_running(__int64 a1, _BYTE *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  if ( (tgt_dfs_is_5ghz_supported_in_pdev(a1) & 1) == 0 )
    return 0;
  if ( wlan_pdev_get_dfs_obj(a1) )
  {
    *a2 = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "tgt_dfs_is_precac_timer_running");
    return 16;
  }
}
