__int64 __fastcall ucfg_action_oui_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  qdf_trace_msg(0x63u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "ucfg_action_oui_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(
                       0x1Cu,
                       (__int64)action_oui_psoc_create_notification,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: Failed to unregister psoc create handler",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ucfg_action_oui_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(
                       0x1Cu,
                       (__int64)action_oui_psoc_destroy_notification,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: Failed to unregister psoc delete handler",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "ucfg_action_oui_deinit");
  return qdf_trace_msg(0x63u, 8u, "%s: exit", v24, v25, v26, v27, v28, v29, v30, v31, "ucfg_action_oui_deinit");
}
