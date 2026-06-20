__int64 __fastcall ucfg_action_oui_init(
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
  unsigned int handler; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19
  const char *v26; // x2
  unsigned int v27; // w1
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  qdf_trace_msg(0x63u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "ucfg_action_oui_init");
  handler = wlan_objmgr_register_psoc_create_handler(
              0x1Cu,
              (__int64)action_oui_psoc_create_notification,
              0,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15);
  if ( handler )
  {
    v25 = handler;
    v26 = "%s: Failed to register psoc create handler";
    v27 = 2;
  }
  else
  {
    v25 = wlan_objmgr_register_psoc_destroy_handler(
            0x1Cu,
            (__int64)action_oui_psoc_destroy_notification,
            0,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v25 )
    {
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: Failed to register psoc delete handler",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "ucfg_action_oui_init");
      wlan_objmgr_unregister_psoc_create_handler(
        0x1Cu,
        (__int64)action_oui_psoc_create_notification,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43);
      goto LABEL_6;
    }
    v26 = "%s: psoc create/delete notifications registered";
    v27 = 8;
  }
  qdf_trace_msg(0x63u, v27, v26, v17, v18, v19, v20, v21, v22, v23, v24, "ucfg_action_oui_init");
LABEL_6:
  qdf_trace_msg(0x63u, 8u, "%s: exit", v28, v29, v30, v31, v32, v33, v34, v35, "ucfg_action_oui_init");
  return v25;
}
