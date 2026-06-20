__int64 __fastcall utils_dfs_get_usenol(__int64 a1, _WORD *a2)
{
  __int64 dfs_obj; // x0
  __int16 use_nol; // w8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  use_nol = dfs_get_use_nol(dfs_obj);
  *a2 = use_nol;
  return 0;
}
