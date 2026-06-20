__int64 __fastcall wlan_scan_register_cached_scan_ev_handler(
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
  unsigned int v10; // w20
  __int64 result; // x0
  unsigned int v12; // w1
  int v13; // w30
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( !a1 )
    goto LABEL_7;
  v10 = *(unsigned __int8 *)(a1 + 40);
  result = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( !result )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
LABEL_7:
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: NULL pointer, pdev: 0x%pK, scan_obj: 0x%pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_pdev_get_pdev_scan_ev_handlers",
      a1,
      0);
    return qdf_trace_msg(
             0x15u,
             8u,
             "%s: null pdev_ev_handler",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "wlan_scan_register_cached_scan_ev_handler");
  }
  if ( v10 < 2 )
  {
    if ( result + 1616LL * v10 != -14624 )
    {
      *(_QWORD *)(result + 1616LL * v10 + 16232) = scm_scan_cached_scan_report_ev_handler;
      return result;
    }
    return qdf_trace_msg(
             0x15u,
             8u,
             "%s: null pdev_ev_handler",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "wlan_scan_register_cached_scan_ev_handler");
  }
  __break(0x5512u);
  if ( v13 )
    JUMPOUT(0x21C12C);
  return ce_per_engine_service(result, v12);
}
