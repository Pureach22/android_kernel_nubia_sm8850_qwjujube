__int64 __fastcall utils_dfs_nol_update(__int64 a1)
{
  __int64 dfs_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  dfs_nol_update(dfs_obj, v2, v3, v4, v5, v6, v7, v8, v9);
  return 0;
}
