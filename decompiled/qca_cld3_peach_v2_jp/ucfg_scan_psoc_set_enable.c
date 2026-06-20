__int64 __fastcall ucfg_scan_psoc_set_enable(__int64 a1, int a2)
{
  _DWORD *comp_private_obj; // x0
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

  comp_private_obj = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    *comp_private_obj &= ~a2;
    qdf_trace_msg(0x15u, 8u, "%s: Psoc scan_disabled %x", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_scan_psoc_set_enable");
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
      "wlan_scan_psoc_set_enable",
      938);
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
      "wlan_scan_psoc_set_enable");
    return 29;
  }
}
