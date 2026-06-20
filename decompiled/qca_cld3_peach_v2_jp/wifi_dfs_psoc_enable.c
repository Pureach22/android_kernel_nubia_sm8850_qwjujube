__int64 __fastcall wifi_dfs_psoc_enable(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19
  const char *v11; // x2

  if ( (unsigned int)tgt_dfs_reg_ev_handler() )
  {
    v10 = 16;
    v11 = "WLAN_DEBUG_DFS_ALWAYS : %s: tgt_dfs_reg_ev_handler failed";
LABEL_5:
    qdf_trace_msg(0x27u, 2u, v11, v2, v3, v4, v5, v6, v7, v8, v9, "wifi_dfs_psoc_enable");
    return v10;
  }
  v10 = wlan_serialization_register_comp_info_cb(a1, 0x10u, 0, (__int64)dfs_scan_serialization_comp_info_cb);
  if ( v10 )
  {
    v11 = "WLAN_DEBUG_DFS_ALWAYS : %s: Serialize scan cmd register failed";
    goto LABEL_5;
  }
  return v10;
}
