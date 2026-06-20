__int64 __fastcall ucfg_qmi_deinit(
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
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int handler; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  qdf_trace_msg(0x9Du, 8u, "%s: QMI module dispatcher deinit", a1, a2, a3, a4, a5, a6, a7, a8, "ucfg_qmi_deinit");
  v16 = wlan_objmgr_unregister_psoc_destroy_handler(
          0x31u,
          (__int64)qmi_psoc_obj_destroy_notification,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15);
  if ( v16 )
    qdf_trace_msg(
      0x9Du,
      2u,
      "%s: Failed to unregister QMI psoc delete handle:%d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_qmi_deinit",
      v16);
  handler = wlan_objmgr_unregister_psoc_create_handler(
              0x31u,
              (__int64)qmi_psoc_obj_create_notification,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24);
  if ( handler )
    qdf_trace_msg(
      0x9Du,
      2u,
      "%s: Failed to unregister QMI psoc create handle:%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ucfg_qmi_deinit",
      handler);
  return handler;
}
