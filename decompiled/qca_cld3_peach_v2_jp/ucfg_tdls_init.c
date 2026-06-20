__int64 __fastcall ucfg_tdls_init(
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
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  qdf_trace_msg(0, 4u, "%s: tdls module dispatcher init", a1, a2, a3, a4, a5, a6, a7, a8, "ucfg_tdls_init");
  handler = wlan_objmgr_register_psoc_create_handler(
              0xAu,
              (__int64)tdls_psoc_obj_create_notification,
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
      0,
      2u,
      "%s: Failed to register psoc create handler for tdls",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_tdls_init");
  }
  else
  {
    v26 = wlan_objmgr_register_psoc_destroy_handler(
            0xAu,
            (__int64)tdls_psoc_obj_destroy_notification,
            0,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v26 )
    {
      v25 = v26;
      qdf_trace_msg(
        0,
        2u,
        "%s: Failed to register psoc delete handler for tdls",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "ucfg_tdls_init");
    }
    else
    {
      v43 = wlan_objmgr_register_vdev_create_handler(
              0xAu,
              (__int64)tdls_vdev_obj_create_notification,
              0,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34);
      if ( v43 )
      {
        v25 = v43;
        qdf_trace_msg(
          0,
          2u,
          "%s: Failed to register vdev create handler for tdls",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "ucfg_tdls_init");
      }
      else
      {
        v25 = wlan_objmgr_register_vdev_destroy_handler(
                0xAu,
                (__int64)tdls_vdev_obj_destroy_notification,
                0,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51);
        if ( !v25 )
        {
          qdf_trace_msg(
            0,
            4u,
            "%s: tdls module dispatcher init done",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "ucfg_tdls_init");
          return v25;
        }
        qdf_trace_msg(
          0,
          2u,
          "%s: Failed to register vdev create handler for tdls",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "ucfg_tdls_init");
        wlan_objmgr_unregister_vdev_create_handler(
          0xAu,
          (__int64)tdls_vdev_obj_create_notification,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75);
      }
      wlan_objmgr_unregister_psoc_destroy_handler(
        0xAu,
        (__int64)tdls_psoc_obj_destroy_notification,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59);
    }
    wlan_objmgr_unregister_psoc_create_handler(
      0xAu,
      (__int64)tdls_psoc_obj_create_notification,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42);
  }
  return v25;
}
