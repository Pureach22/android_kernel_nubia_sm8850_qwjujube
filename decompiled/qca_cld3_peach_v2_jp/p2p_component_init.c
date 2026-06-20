__int64 __fastcall p2p_component_init(
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
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7

  handler = wlan_objmgr_register_psoc_create_handler(
              5u,
              (__int64)p2p_psoc_obj_create_notification,
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
      0x4Eu,
      2u,
      "%s: Failed to register p2p obj create handler",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "p2p_component_init");
  }
  else
  {
    v18 = wlan_objmgr_register_psoc_destroy_handler(
            5u,
            (__int64)p2p_psoc_obj_destroy_notification,
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
        0x4Eu,
        2u,
        "%s: Failed to register p2p obj delete handler",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "p2p_component_init");
    }
    else
    {
      v35 = wlan_objmgr_register_vdev_create_handler(
              5u,
              (__int64)p2p_vdev_obj_create_notification,
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
          0x4Eu,
          2u,
          "%s: Failed to register p2p vdev create handler",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "p2p_component_init");
      }
      else
      {
        v52 = wlan_objmgr_register_vdev_destroy_handler(
                5u,
                (__int64)p2p_vdev_obj_destroy_notification,
                0,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43);
        if ( v52 )
        {
          v17 = v52;
          qdf_trace_msg(
            0x4Eu,
            2u,
            "%s: Failed to register p2p vdev delete handler",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "p2p_component_init");
        }
        else
        {
          v69 = wlan_objmgr_register_peer_create_handler(
                  5u,
                  (__int64)p2p_peer_obj_create_notification,
                  0,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60);
          if ( v69 )
          {
            v17 = v69;
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: Failed to register p2p peer create handler",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "p2p_component_init");
          }
          else
          {
            v17 = wlan_objmgr_register_peer_destroy_handler(
                    5u,
                    (__int64)p2p_peer_obj_destroy_notification,
                    0,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77);
            if ( !v17 )
            {
              qdf_trace_msg(
                0x4Eu,
                8u,
                "%s: Register p2p obj handler successful",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "p2p_component_init");
              return v17;
            }
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: Failed to register p2p peer destroy handler",
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              "p2p_component_init");
            wlan_objmgr_unregister_peer_create_handler(
              5u,
              (__int64)p2p_peer_obj_create_notification,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              v101);
          }
          wlan_objmgr_unregister_vdev_destroy_handler(
            5u,
            (__int64)p2p_vdev_obj_destroy_notification,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85);
        }
        wlan_objmgr_unregister_vdev_create_handler(
          5u,
          (__int64)p2p_vdev_obj_create_notification,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68);
      }
      wlan_objmgr_unregister_psoc_destroy_handler(
        5u,
        (__int64)p2p_psoc_obj_destroy_notification,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51);
    }
    wlan_objmgr_unregister_psoc_create_handler(
      5u,
      (__int64)p2p_psoc_obj_create_notification,
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
