__int64 __fastcall wlan_regulatory_init(
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
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7

  handler = wlan_objmgr_register_psoc_create_handler(
              0xDu,
              (__int64)wlan_regulatory_psoc_obj_created_notification,
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
      0x51u,
      2u,
      "%s: failed to register reg psoc obj create handler",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_regulatory_init");
    return v17;
  }
  if ( (unsigned int)wlan_objmgr_register_psoc_destroy_handler(
                       0xDu,
                       (__int64)wlan_regulatory_psoc_obj_destroyed_notification,
                       0,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16) )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: failed to register reg psoc obj create handler",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_regulatory_init");
  }
  else
  {
    if ( (unsigned int)wlan_objmgr_register_pdev_create_handler(
                         0xDu,
                         (__int64)&wlan_regulatory_pdev_obj_created_notification,
                         0,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26) )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: failed to register reg psoc obj create handler",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlan_regulatory_init");
    }
    else
    {
      if ( !(unsigned int)wlan_objmgr_register_pdev_destroy_handler(
                            0xDu,
                            (__int64)wlan_regulatory_pdev_obj_destroyed_notification,
                            0,
                            v35,
                            v36,
                            v37,
                            v38,
                            v39,
                            v40,
                            v41,
                            v42) )
      {
        channel_map = (__int64)&channel_map_global;
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: regulatory handlers registered with obj mgr",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wlan_regulatory_init");
        return 0;
      }
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: failed to register reg psoc obj create handler",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "wlan_regulatory_init");
      wlan_objmgr_unregister_pdev_create_handler(
        0xDu,
        (__int64)&wlan_regulatory_pdev_obj_created_notification,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66);
    }
    wlan_objmgr_unregister_psoc_destroy_handler(
      0xDu,
      (__int64)wlan_regulatory_psoc_obj_destroyed_notification,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50);
  }
  wlan_objmgr_unregister_psoc_create_handler(
    0xDu,
    (__int64)wlan_regulatory_psoc_obj_created_notification,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34);
  return 16;
}
