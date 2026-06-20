__int64 __fastcall ipa_init(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
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
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w19
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  qdf_trace_msg(0x61u, 4u, "%s: ipa module dispatcher init", a1, a2, a3, a4, a5, a6, a7, a8, "ipa_init");
  if ( (ipa_check_hw_present() & 1) != 0 )
  {
    handler = wlan_objmgr_register_psoc_create_handler(
                0x1Au,
                (__int64)ipa_psoc_obj_create_notification,
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
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Failed to register pdev create handler for ipa",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "ipa_init");
      return v25;
    }
    v27 = wlan_objmgr_register_psoc_destroy_handler(
            0x1Au,
            (__int64)ipa_psoc_obj_destroy_notification,
            0,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v27 )
    {
      v36 = v27;
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Failed to register pdev destroy handler for ipa",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "ipa_init");
      wlan_objmgr_unregister_psoc_create_handler(
        0x1Au,
        (__int64)ipa_psoc_obj_create_notification,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44);
      return v36;
    }
    qdf_mutex_create((__int64)&g_init_deinit_lock);
  }
  else
  {
    qdf_trace_msg(0x61u, 4u, "%s: ipa hw not present", v8, v9, v10, v11, v12, v13, v14, v15, "ipa_init");
  }
  return 0;
}
