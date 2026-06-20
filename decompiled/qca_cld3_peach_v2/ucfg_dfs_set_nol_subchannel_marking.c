__int64 __fastcall ucfg_dfs_set_nol_subchannel_marking(__int64 a1, char a2)
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
  if ( !dfs_obj )
    return 16;
  dfs_set_nol_subchannel_marking(dfs_obj, a2 & 1, v4, v5, v6, v7, v8, v9, v10, v11);
  return 0;
}
