__int64 __fastcall utils_dfs_reset(__int64 a1)
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
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  v10 = dfs_obj;
  dfs_reset(dfs_obj, v2, v3, v4, v5, v6, v7, v8, v9);
  dfs_nol_update(v10, v11, v12, v13, v14, v15, v16, v17, v18);
  return 0;
}
