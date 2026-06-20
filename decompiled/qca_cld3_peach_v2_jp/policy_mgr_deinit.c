__int64 __fastcall policy_mgr_deinit(
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
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int handler; // w19
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7

  if ( (unsigned int)wlan_objmgr_unregister_psoc_status_handler(
                       6u,
                       (__int64)policy_mgr_psoc_obj_status_cb,
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister psoc obj status cback",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(
                       6u,
                       (__int64)policy_mgr_psoc_obj_destroy_cb,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister psoc obj delete cback",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(
                       6u,
                       (__int64)policy_mgr_psoc_obj_create_cb,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister psoc obj create cback",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_pdev_destroy_handler(
                       6u,
                       (__int64)policy_mgr_pdev_obj_destroy_cb,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister pdev obj delete cback",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_pdev_create_handler(
                       6u,
                       (__int64)policy_mgr_pdev_obj_create_cb,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       v39) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister pdev obj create cback",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_vdev_status_handler(
                       6u,
                       (__int64)policy_mgr_vdev_obj_status_cb,
                       v40,
                       v41,
                       v42,
                       v43,
                       v44,
                       v45,
                       v46,
                       v47) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister vdev obj status cback",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "policy_mgr_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_vdev_destroy_handler(
                       6u,
                       (__int64)policy_mgr_vdev_obj_destroy_cb,
                       v48,
                       v49,
                       v50,
                       v51,
                       v52,
                       v53,
                       v54,
                       v55) )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister vdev obj delete cback",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "policy_mgr_deinit");
  handler = wlan_objmgr_unregister_vdev_create_handler(
              6u,
              (__int64)policy_mgr_vdev_obj_create_cb,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63);
  if ( handler )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to deregister vdev obj create cback",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "policy_mgr_deinit");
  qdf_trace_msg(
    0x4Fu,
    4u,
    "%s: deregistered callbacks with obj mgr successfully",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "policy_mgr_deinit");
  return handler;
}
