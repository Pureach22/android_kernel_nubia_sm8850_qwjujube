__int64 __fastcall ucfg_dfs_get_agile_precac_enable(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = 16;
  if ( a1 && a2 )
  {
    v5 = a1;
    if ( (tgt_dfs_is_5ghz_supported_in_pdev(a1) & 1) != 0 && !wlan_pdev_get_dfs_obj(v5) )
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "ucfg_dfs_get_agile_precac_enable");
    *a2 = 0;
    return 0;
  }
  return result;
}
