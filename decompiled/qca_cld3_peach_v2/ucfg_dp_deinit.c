__int64 __fastcall ucfg_dp_deinit(
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
  unsigned int handler; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w0
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
  unsigned int v52; // w0
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
  unsigned int v70; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w19
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7

  qdf_trace_msg(0x45u, 5u, "%s: DP module dispatcher deinit", a1, a2, a3, a4, a5, a6, a7, a8, "ucfg_dp_deinit");
  mlo_mgr_unregister_link_switch_notifier(46);
  v16 = wlan_objmgr_unregister_peer_destroy_handler(
          0x2Eu,
          (__int64)dp_peer_obj_destroy_notification,
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
      0x45u,
      2u,
      "%s: Failed to unregister DP peer destroy handler: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_dp_deinit",
      v16);
  handler = wlan_objmgr_unregister_peer_create_handler(
              0x2Eu,
              (__int64)dp_peer_obj_create_notification,
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
      0x45u,
      2u,
      "%s: Failed to unregister DP peer create handler: %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ucfg_dp_deinit",
      handler);
  v34 = wlan_objmgr_unregister_vdev_destroy_handler(
          0x2Eu,
          (__int64)dp_vdev_obj_destroy_notification,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33);
  if ( v34 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to unregister vdev delete handler:%d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "ucfg_dp_deinit",
      v34);
  v43 = wlan_objmgr_unregister_vdev_create_handler(
          0x2Eu,
          (__int64)dp_vdev_obj_create_notification,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42);
  if ( v43 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to unregister vdev create handler:%d",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "ucfg_dp_deinit",
      v43);
  v52 = wlan_objmgr_unregister_pdev_destroy_handler(
          0x2Eu,
          (__int64)dp_pdev_obj_destroy_notification,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51);
  if ( v52 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to unregister pdev destroy handler:%d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "ucfg_dp_deinit",
      v52);
  v61 = wlan_objmgr_unregister_pdev_create_handler(
          0x2Eu,
          (__int64)dp_pdev_obj_create_notification,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60);
  if ( v61 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to unregister pdev create handler:%d",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "ucfg_dp_deinit",
      v61);
  v70 = wlan_objmgr_unregister_psoc_destroy_handler(
          0x2Eu,
          (__int64)dp_psoc_obj_destroy_notification,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69);
  if ( v70 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to unregister DP psoc delete handle:%d",
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      "ucfg_dp_deinit",
      v70);
  v79 = wlan_objmgr_unregister_psoc_create_handler(
          0x2Eu,
          (__int64)dp_psoc_obj_create_notification,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78);
  if ( v79 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to unregister DP psoc create handle:%d",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "ucfg_dp_deinit",
      v79);
  dp_free_ctx();
  return v79;
}
