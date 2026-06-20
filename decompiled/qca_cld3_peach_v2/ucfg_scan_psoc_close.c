__int64 __fastcall ucfg_scan_psoc_close(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 comp_private_obj; // x20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v36; // x2

  qdf_trace_msg(0x15u, 8u, "%s: psoc close: 0x%pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_scan_psoc_close", a1);
  if ( !a1 )
  {
    v36 = "%s: null psoc";
LABEL_8:
    qdf_trace_msg(0x15u, 2u, v36, v10, v11, v12, v13, v14, v15, v16, v17, "ucfg_scan_psoc_close");
    return 16;
  }
  scm_db_deinit(a1, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( !wlan_objmgr_psoc_get_comp_private_obj(a1, 3u) )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_psoc_close",
      1364);
    v36 = "%s: Failed to get scan object";
    goto LABEL_8;
  }
  pmo_unregister_suspend_handler(3, ucfg_scan_suspend_handler);
  pmo_unregister_resume_handler(3, ucfg_scan_resume_handler);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_global_deinit",
      848);
  qdf_runtime_lock_deinit((__int64 *)(comp_private_obj + 18584));
  _qdf_wake_lock_destroy(comp_private_obj + 18384);
  scm_channel_list_db_deinit(a1);
  return 0;
}
