__int64 __fastcall ucfg_scan_set_miracast(__int64 a1, char a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    *(_BYTE *)(comp_private_obj + 18737) = a2 & 1;
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: set miracast_enable to %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_scan_set_miracast");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_set_miracast",
      488);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Failed to get scan object",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ucfg_scan_set_miracast");
    return 29;
  }
}
