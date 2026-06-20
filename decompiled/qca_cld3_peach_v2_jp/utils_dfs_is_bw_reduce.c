__int64 __fastcall utils_dfs_is_bw_reduce(__int64 a1, _BYTE *a2)
{
  __int64 dfs_obj; // x0
  __int64 v4; // x8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  v4 = dfs_obj;
  *a2 = *(_BYTE *)(v4 + 14992);
  return 0;
}
