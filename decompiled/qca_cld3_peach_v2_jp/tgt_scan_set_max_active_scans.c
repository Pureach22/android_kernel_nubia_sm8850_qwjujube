__int64 __fastcall tgt_scan_set_max_active_scans(
        __int64 a1,
        int a2,
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
  const char *v21; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      *(_DWORD *)(comp_private_obj + 1732) = a2;
      return 0;
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_get_def_params",
      878);
    v21 = "%s: wlan_scan_psoc_get_def_params returned NULL";
  }
  else
  {
    v21 = "%s: null psoc";
  }
  qdf_trace_msg(0x15u, 2u, v21, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_scan_set_max_active_scans");
  return 29;
}
