__int64 __fastcall ucfg_scan_set_global_config(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_set_global_config",
      1606);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Failed to get scan object config:%d, val:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ucfg_scan_set_global_config",
      a2,
      a3);
    return 4;
  }
  if ( a2 != 1 )
  {
    if ( !a2 )
    {
      *(_BYTE *)(comp_private_obj + 18738) = a3 != 0;
      return 0;
    }
    return 4;
  }
  *(_BYTE *)(comp_private_obj + 18739) = a3 != 0;
  return 0;
}
