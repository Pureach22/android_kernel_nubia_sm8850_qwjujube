__int64 __fastcall tgt_dfs_process_radar_ind(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 dfs_obj; // x0
  __int64 v12; // x20
  unsigned int v13; // w19
  const char *v15; // x2

  if ( a1 )
  {
    dfs_obj = wlan_pdev_get_dfs_obj(a1);
    if ( dfs_obj )
    {
      v12 = dfs_obj;
      v13 = dfs_process_radar_ind(dfs_obj, a2);
      dfs_inc_num_radar(v12);
      return v13;
    }
    v15 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is null";
  }
  else
  {
    v15 = "WLAN_DEBUG_DFS_ALWAYS : %s: null pdev";
  }
  qdf_trace_msg(0x27u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_dfs_process_radar_ind");
  return 16;
}
