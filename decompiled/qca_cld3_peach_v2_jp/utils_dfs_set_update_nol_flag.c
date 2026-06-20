__int64 __fastcall utils_dfs_set_update_nol_flag(__int64 a1, char a2)
{
  __int64 dfs_obj; // x0

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  dfs_set_update_nol_flag(dfs_obj, a2 & 1);
  return 0;
}
