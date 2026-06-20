__int64 __fastcall disa_init(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
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
  unsigned int v32; // w19
  unsigned int handler; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7

  qdf_trace_msg(0x5Cu, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "disa_init");
  if ( !(unsigned int)disa_allocate_ctx(v8, v9, v10, v11, v12, v13, v14, v15) )
  {
    handler = wlan_objmgr_register_psoc_create_handler(
                0x15u,
                (__int64)disa_psoc_object_created_notification,
                0,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23);
    if ( handler )
    {
      v32 = handler;
      qdf_trace_msg(
        0x5Cu,
        2u,
        "%s: unable to register psoc create handler",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "disa_init");
    }
    else
    {
      v32 = wlan_objmgr_register_psoc_destroy_handler(
              0x15u,
              (__int64)disa_psoc_object_destroyed_notification,
              0,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41);
      if ( !v32 )
        goto LABEL_8;
      qdf_trace_msg(
        0x5Cu,
        2u,
        "%s: unable to register psoc destroy handler",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "disa_init");
      wlan_objmgr_unregister_psoc_create_handler(
        0x15u,
        (__int64)disa_psoc_object_created_notification,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57);
    }
    disa_free_ctx(v42, v43, v44, v45, v46, v47, v48, v49);
    goto LABEL_8;
  }
  qdf_trace_msg(0x5Cu, 2u, "%s: unable to allocate disa ctx", v16, v17, v18, v19, v20, v21, v22, v23, "disa_init");
  v32 = 5;
LABEL_8:
  qdf_trace_msg(0x5Cu, 8u, "%s: exit", v24, v25, v26, v27, v28, v29, v30, v31, "disa_init");
  return v32;
}
