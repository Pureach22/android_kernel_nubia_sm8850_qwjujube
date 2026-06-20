__int64 __fastcall ucfg_scan_get_max_active_scans(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v19; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
      return *(unsigned int *)(comp_private_obj + 1732);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_get_def_params",
      878);
    v19 = "%s: Failed to get scan object";
  }
  else
  {
    v19 = "%s: null psoc";
  }
  qdf_trace_msg(0x15u, 2u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_scan_get_max_active_scans");
  return 0;
}
