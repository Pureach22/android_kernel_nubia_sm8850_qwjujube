__int64 __fastcall utils_dfs_set_cac_timer_running(__int64 a1, char a2)
{
  __int64 dfs_obj; // x0
  __int64 v4; // x8
  char v5; // w10

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  v4 = dfs_obj;
  v5 = *(_BYTE *)(dfs_obj + 14852);
  *(_BYTE *)(v4 + 14852) = v5 & 0xFD | (2 * (a2 & 1));
  return 0;
}
