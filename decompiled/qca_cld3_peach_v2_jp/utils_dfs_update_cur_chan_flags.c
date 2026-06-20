__int64 __fastcall utils_dfs_update_cur_chan_flags(__int64 a1, __int64 a2, __int16 a3)
{
  __int64 dfs_obj; // x0

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  dfs_update_cur_chan_flags(dfs_obj, a2, a3);
  return 0;
}
