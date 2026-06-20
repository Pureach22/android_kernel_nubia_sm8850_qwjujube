__int64 __fastcall utils_dfs_is_freq_in_nol(__int64 a1, int a2)
{
  __int64 dfs_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( dfs_obj )
    LOBYTE(dfs_obj) = dfs_is_freq_in_nol(dfs_obj, a2, v4, v5, v6, v7, v8, v9, v10, v11);
  return dfs_obj & 1;
}
