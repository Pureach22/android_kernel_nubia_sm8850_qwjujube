__int64 policy_mgr_deinit()
{
  int v0; // w0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int handler; // w19
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7

  v0 = mlo_mgr_unregister_link_switch_notifier(6);
  if ( v0 && v0 != 11 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to unregister link switch notifier for policy mgr!",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "policy_mgr_unregister_link_switch_notifier");
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister link switch cback",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_deinit");
  }
  if ( (unsigned int)wlan_objmgr_unregister_psoc_status_handler(
                       6u,
                       (__int64)policy_mgr_psoc_obj_status_cb,
                       v1,
                       v2,
                       v3,
                       v4,
                       v5,
                       v6,
                       v7,
                       v8) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister psoc obj status cback",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(
                       6u,
                       (__int64)policy_mgr_psoc_obj_destroy_cb,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister psoc obj delete cback",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(
                       6u,
                       (__int64)policy_mgr_psoc_obj_create_cb,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister psoc obj create cback",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_pdev_destroy_handler(
                       6u,
                       (__int64)policy_mgr_pdev_obj_destroy_cb,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       v39,
                       v40) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister pdev obj delete cback",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_pdev_create_handler(
                       6u,
                       (__int64)policy_mgr_pdev_obj_create_cb,
                       v41,
                       v42,
                       v43,
                       v44,
                       v45,
                       v46,
                       v47,
                       v48) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister pdev obj create cback",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_vdev_status_handler(
                       6u,
                       (__int64)policy_mgr_vdev_obj_status_cb,
                       v49,
                       v50,
                       v51,
                       v52,
                       v53,
                       v54,
                       v55,
                       v56) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister vdev obj status cback",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_vdev_destroy_handler(
                       6u,
                       (__int64)policy_mgr_vdev_obj_destroy_cb,
                       v57,
                       v58,
                       v59,
                       v60,
                       v61,
                       v62,
                       v63,
                       v64) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister vdev obj delete cback",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "policy_mgr_deinit");
  handler = wlan_objmgr_unregister_vdev_create_handler(
              6u,
              (__int64)policy_mgr_vdev_obj_create_cb,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72);
  if ( handler )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister vdev obj create cback",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "policy_mgr_deinit");
  qdf_trace_msg(
    0x4Fu,
    4u,
    "%s: deregistered callbacks with obj mgr successfully",
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    "policy_mgr_deinit");
  return handler;
}
