__int64 __fastcall wifi_pos_deinit(
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
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int handler; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7

  if ( (unsigned int)wlan_objmgr_unregister_peer_destroy_handler(
                       9u,
                       (__int64)wifi_pos_peer_object_destroyed_notification,
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8) )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: unable to unregister peer destroy handle",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wifi_pos_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_peer_create_handler(
                       9u,
                       (__int64)wifi_pos_peer_object_created_notification,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: unable to unregister peer create handle",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wifi_pos_deinit");
  v24 = wlan_objmgr_unregister_vdev_destroy_handler(
          9u,
          (__int64)wifi_pos_vdev_destroyed_notification,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23);
  if ( v24 )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: unregister_vdev_destroy_handler failed, status: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wifi_pos_deinit",
      v24);
  handler = wlan_objmgr_unregister_vdev_create_handler(
              9u,
              (__int64)wifi_pos_vdev_created_notification,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32);
  if ( handler )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: unregister_vdev_create_handler failed, status: %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wifi_pos_deinit",
      handler);
  v42 = wlan_objmgr_unregister_psoc_create_handler(
          9u,
          (__int64)wifi_pos_psoc_obj_created_notification,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41);
  if ( v42 )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: unregister_psoc_create_handler failed, status: %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "wifi_pos_deinit",
      v42);
  }
  else
  {
    v51 = wlan_objmgr_unregister_psoc_destroy_handler(
            9u,
            (__int64)wifi_pos_psoc_obj_destroyed_notification,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50);
    if ( (_DWORD)v51 )
      v51 = qdf_trace_msg(
              0x25u,
              2u,
              "%s: unregister_psoc_destroy_handler failed, status: %d",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "wifi_pos_deinit",
              (unsigned int)v51);
    wifi_pos_lock_deinit(v51);
  }
  return v42;
}
