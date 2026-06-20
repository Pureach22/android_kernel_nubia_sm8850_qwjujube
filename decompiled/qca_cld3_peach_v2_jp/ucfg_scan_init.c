__int64 __fastcall ucfg_scan_init(
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

  handler = wlan_objmgr_register_psoc_create_handler(
              3u,
              (__int64)wlan_scan_psoc_created_notification,
              0,
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8);
  if ( handler )
  {
    v17 = handler;
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Failed to register psoc create handler",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "ucfg_scan_init");
  }
  else
  {
    v18 = wlan_objmgr_register_psoc_destroy_handler(
            3u,
            (__int64)wlan_scan_psoc_destroyed_notification,
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
        0x15u,
        2u,
        "%s: Failed to create psoc delete handler",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "ucfg_scan_init");
    }
    else
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: scan psoc create and delete handler registered with objmgr",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "ucfg_scan_init");
      v43 = wlan_objmgr_register_vdev_create_handler(
              3u,
              (__int64)wlan_scan_vdev_created_notification,
              0,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42);
      if ( v43 )
      {
        v17 = v43;
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: Failed to register vdev create handler",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "ucfg_scan_init");
      }
      else
      {
        v17 = wlan_objmgr_register_vdev_destroy_handler(
                3u,
                (__int64)wlan_scan_vdev_destroyed_notification,
                0,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51);
        if ( !v17 )
        {
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: scan vdev create and delete handler registered with objmgr",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "ucfg_scan_init");
          return v17;
        }
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: Failed to destroy vdev delete handler",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "ucfg_scan_init");
        wlan_objmgr_unregister_vdev_create_handler(
          3u,
          (__int64)wlan_scan_vdev_created_notification,
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
        3u,
        (__int64)wlan_scan_psoc_destroyed_notification,
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
      3u,
      (__int64)wlan_scan_psoc_created_notification,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34);
  }
  return v17;
}
