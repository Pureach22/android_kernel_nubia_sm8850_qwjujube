__int64 __fastcall ucfg_dfs_getnol(__int64 a1, int *a2)
{
  __int64 dfs_obj; // x0

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  dfs_getnol(dfs_obj, a2);
  return 0;
}
