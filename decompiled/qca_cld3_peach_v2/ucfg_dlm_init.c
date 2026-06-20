__int64 __fastcall ucfg_dlm_init(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  unsigned int handler; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w19
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
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

  handler = wlan_objmgr_register_pdev_create_handler(
              0x20u,
              (__int64)dlm_pdev_object_created_notification,
              0,
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8);
  if ( !handler )
  {
    v18 = wlan_objmgr_register_pdev_destroy_handler(
            0x20u,
            (__int64)dlm_pdev_object_destroyed_notification,
            0,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16);
    if ( v18 )
    {
      v17 = v18;
      qdf_trace_msg(
        0x6Du,
        2u,
        "%s: pdev destroy register notification failed",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "ucfg_dlm_init");
    }
    else
    {
      v35 = wlan_objmgr_register_psoc_create_handler(
              0x20u,
              (__int64)dlm_psoc_object_created_notification,
              0,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26);
      if ( v35 )
      {
        v17 = v35;
        qdf_trace_msg(
          0x6Du,
          2u,
          "%s: psoc create register notification failed",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "ucfg_dlm_init");
      }
      else
      {
        v17 = wlan_objmgr_register_psoc_destroy_handler(
                0x20u,
                (__int64)dlm_psoc_object_destroyed_notification,
                0,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43);
        if ( !v17 )
          return v17;
        qdf_trace_msg(
          0x6Du,
          2u,
          "%s: psoc destroy register notification failed",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "ucfg_dlm_init");
        wlan_objmgr_unregister_psoc_create_handler(
          0x20u,
          (__int64)dlm_psoc_object_created_notification,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67);
      }
      wlan_objmgr_unregister_pdev_destroy_handler(
        0x20u,
        (__int64)dlm_pdev_object_destroyed_notification,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51);
    }
    wlan_objmgr_unregister_pdev_create_handler(
      0x20u,
      (__int64)dlm_pdev_object_created_notification,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34);
    return v17;
  }
  v17 = handler;
  qdf_trace_msg(
    0x6Du,
    2u,
    "%s: pdev create register notification failed",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "ucfg_dlm_init");
  return v17;
}
