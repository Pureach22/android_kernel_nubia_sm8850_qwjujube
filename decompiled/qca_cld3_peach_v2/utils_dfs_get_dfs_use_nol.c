__int64 __fastcall utils_dfs_get_dfs_use_nol(__int64 a1, _DWORD *a2)
{
  __int64 dfs_obj; // x0
  int use_nol; // w8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  use_nol = dfs_get_use_nol(dfs_obj);
  *a2 = use_nol;
  return 0;
}
