__int64 __fastcall utils_dfs_get_update_nol_flag(__int64 a1, _BYTE *a2)
{
  __int64 dfs_obj; // x0
  char update_nol_flag; // w8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  update_nol_flag = dfs_get_update_nol_flag(dfs_obj);
  *a2 = update_nol_flag & 1;
  return 0;
}
