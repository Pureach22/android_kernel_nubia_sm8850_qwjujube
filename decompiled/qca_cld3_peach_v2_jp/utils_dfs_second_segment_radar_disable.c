__int64 __fastcall utils_dfs_second_segment_radar_disable(__int64 a1)
{
  __int64 dfs_obj; // x0

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  dfs_second_segment_radar_disable(dfs_obj);
  return 0;
}
