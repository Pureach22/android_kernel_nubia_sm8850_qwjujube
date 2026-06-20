__int64 __fastcall ucfg_dfs_update_config(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8

  if ( a1 && a2 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x10u);
    if ( comp_private_obj )
    {
      v20 = comp_private_obj;
      *(_BYTE *)(v20 + 16) = *a2;
      return 0;
    }
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: Failed to get dfs psoc component",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_dfs_update_config");
  }
  else
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: psoc: 0x%pK, req: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_dfs_update_config",
      a1,
      a2);
  }
  return 16;
}
