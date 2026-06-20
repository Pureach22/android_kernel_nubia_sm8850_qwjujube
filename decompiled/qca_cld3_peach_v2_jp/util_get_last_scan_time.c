__int64 __fastcall util_get_last_scan_time(
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
  __int64 v9; // x8
  int v10; // w19
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 3u, "%s: null vdev", a2, a3, a4, a5, a6, a7, a8, a9, "util_get_last_scan_time");
    return 0;
  }
  v9 = *(_QWORD *)(a1 + 152);
  v10 = *(unsigned __int8 *)(v9 + 40);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v9 + 80), 3u);
  if ( !comp_private_obj )
  {
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
      "wlan_pdev_get_scan_obj",
      764);
    return 0;
  }
  if ( !v10 )
    return *(_QWORD *)(comp_private_obj + 16248);
  __break(0x5512u);
  return util_is_rsnxe_h2e_capable(comp_private_obj);
}
