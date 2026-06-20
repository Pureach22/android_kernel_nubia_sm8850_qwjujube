__int64 __fastcall tgt_dfs_process_phyerr_filter_offload(__int64 a1)
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

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( dfs_obj )
  {
    if ( *(_BYTE *)(dfs_obj + 14954) == 1 )
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: Unexpected phyerror as DFS is offloaded, pdev_id: %d",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "tgt_dfs_process_phyerr_filter_offload",
        *(unsigned __int8 *)(a1 + 40));
    return 0;
  }
  else
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
      "tgt_dfs_process_phyerr_filter_offload");
    return 16;
  }
}
