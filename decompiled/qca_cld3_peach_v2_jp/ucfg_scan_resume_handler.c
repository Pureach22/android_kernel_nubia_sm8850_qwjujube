__int64 __fastcall ucfg_scan_resume_handler(__int64 a1)
{
  _DWORD *comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  comp_private_obj = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    *comp_private_obj &= ~1u;
    qdf_trace_msg(0x15u, 8u, "%s: Psoc scan_disabled %x", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_scan_psoc_set_enable");
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_set_enable",
      938);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Failed to get scan object",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_scan_psoc_set_enable");
  }
  return 0;
}
