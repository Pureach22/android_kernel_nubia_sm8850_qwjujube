__int64 __fastcall ucfg_dp_init(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  unsigned int handler; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  unsigned int v27; // w0
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
  unsigned int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned int v112; // w0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  unsigned int v129; // w0
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7

  qdf_trace_msg(0x45u, 5u, "%s: DP module dispatcher init", a1, a2, a3, a4, a5, a6, a7, a8, "ucfg_dp_init");
  if ( (unsigned int)dp_allocate_ctx() )
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP ctx allocation failed", v8, v9, v10, v11, v12, v13, v14, v15, "ucfg_dp_init");
    return 5;
  }
  handler = wlan_objmgr_register_psoc_create_handler(
              0x2Eu,
              (__int64)dp_psoc_obj_create_notification,
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
    v26 = handler;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to register psoc create handler for DP",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "ucfg_dp_init");
  }
  else
  {
    v27 = wlan_objmgr_register_psoc_destroy_handler(
            0x2Eu,
            (__int64)dp_psoc_obj_destroy_notification,
            0,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25);
    if ( v27 )
    {
      v26 = v27;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to register psoc destroy handler for DP",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "ucfg_dp_init");
    }
    else
    {
      v44 = wlan_objmgr_register_pdev_create_handler(
              0x2Eu,
              (__int64)dp_pdev_obj_create_notification,
              0,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35);
      if ( v44 )
      {
        v26 = v44;
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Failed to register pdev create handler for DP",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "ucfg_dp_init");
      }
      else
      {
        v61 = wlan_objmgr_register_pdev_destroy_handler(
                0x2Eu,
                (__int64)dp_pdev_obj_destroy_notification,
                0,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52);
        if ( v61 )
        {
          v26 = v61;
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Failed to register pdev destroy handler for DP",
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            "ucfg_dp_init");
        }
        else
        {
          v78 = wlan_objmgr_register_vdev_create_handler(
                  0x2Eu,
                  (__int64)dp_vdev_obj_create_notification,
                  0,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  v69);
          if ( v78 )
          {
            v26 = v78;
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Failed to register vdev create handler",
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              "ucfg_dp_init");
          }
          else
          {
            v95 = wlan_objmgr_register_vdev_destroy_handler(
                    0x2Eu,
                    (__int64)dp_vdev_obj_destroy_notification,
                    0,
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    v84,
                    v85,
                    v86);
            if ( v95 )
            {
              v26 = v95;
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: Failed to register vdev destroy handler",
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                "ucfg_dp_init");
            }
            else
            {
              v112 = wlan_objmgr_register_peer_create_handler(
                       0x2Eu,
                       (__int64)dp_peer_obj_create_notification,
                       0,
                       v96,
                       v97,
                       v98,
                       v99,
                       v100,
                       v101,
                       v102,
                       v103);
              if ( v112 )
              {
                v26 = v112;
                qdf_trace_msg(
                  0x45u,
                  2u,
                  "%s: wlan_objmgr_register_peer_create_handler failed",
                  v113,
                  v114,
                  v115,
                  v116,
                  v117,
                  v118,
                  v119,
                  v120,
                  "ucfg_dp_init");
              }
              else
              {
                v129 = wlan_objmgr_register_peer_destroy_handler(
                         0x2Eu,
                         (__int64)dp_peer_obj_destroy_notification,
                         0,
                         v113,
                         v114,
                         v115,
                         v116,
                         v117,
                         v118,
                         v119,
                         v120);
                if ( v129 )
                {
                  v26 = v129;
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: wlan_objmgr_register_peer_destroy_handler failed",
                    v130,
                    v131,
                    v132,
                    v133,
                    v134,
                    v135,
                    v136,
                    v137,
                    "ucfg_dp_init");
                }
                else
                {
                  result = mlo_mgr_register_link_switch_notifier(46, dp_link_switch_notification);
                  if ( !(_DWORD)result )
                    return result;
                  v26 = result;
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: wlan_mlomgr_register_link_switch_handler failed",
                    v146,
                    v147,
                    v148,
                    v149,
                    v150,
                    v151,
                    v152,
                    v153,
                    "ucfg_dp_init");
                  wlan_objmgr_unregister_peer_destroy_handler(
                    0x2Eu,
                    (__int64)dp_peer_obj_destroy_notification,
                    v154,
                    v155,
                    v156,
                    v157,
                    v158,
                    v159,
                    v160,
                    v161);
                }
                wlan_objmgr_unregister_peer_create_handler(
                  0x2Eu,
                  (__int64)dp_peer_obj_create_notification,
                  v138,
                  v139,
                  v140,
                  v141,
                  v142,
                  v143,
                  v144,
                  v145);
              }
              wlan_objmgr_unregister_vdev_destroy_handler(
                0x2Eu,
                (__int64)dp_vdev_obj_destroy_notification,
                v121,
                v122,
                v123,
                v124,
                v125,
                v126,
                v127,
                v128);
            }
            wlan_objmgr_unregister_vdev_create_handler(
              0x2Eu,
              (__int64)dp_vdev_obj_create_notification,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              v110,
              v111);
          }
          wlan_objmgr_unregister_pdev_destroy_handler(
            0x2Eu,
            (__int64)dp_pdev_obj_destroy_notification,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94);
        }
        wlan_objmgr_unregister_pdev_create_handler(
          0x2Eu,
          (__int64)dp_pdev_obj_create_notification,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77);
      }
      wlan_objmgr_unregister_psoc_destroy_handler(
        0x2Eu,
        (__int64)dp_psoc_obj_destroy_notification,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60);
    }
    wlan_objmgr_unregister_psoc_create_handler(
      0x2Eu,
      (__int64)dp_psoc_obj_create_notification,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43);
    dp_free_ctx();
  }
  return v26;
}
