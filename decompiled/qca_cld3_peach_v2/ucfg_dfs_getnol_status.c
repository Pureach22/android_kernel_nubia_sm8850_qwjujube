__int64 __fastcall ucfg_dfs_getnol_status(__int64 a1, _BYTE *a2)
{
  __int64 dfs_obj; // x0

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  dfs_getnol_status(dfs_obj, a2);
  return 0;
}
