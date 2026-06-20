__int64 __fastcall utils_dfs_get_nol_timeout(__int64 a1, _DWORD *a2)
{
  __int64 dfs_obj; // x0
  int nol_timeout; // w8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  nol_timeout = dfs_get_nol_timeout(dfs_obj);
  *a2 = nol_timeout;
  return 0;
}
