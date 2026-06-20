__int64 __fastcall nan_deinit(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  unsigned int handler; // w19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  unsigned int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w20
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w20
  unsigned int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w20

  handler = wlan_objmgr_unregister_psoc_create_handler(
              0xFu,
              (__int64)nan_psoc_obj_created_notification,
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8);
  if ( handler )
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: wlan_objmgr_unregister_psoc_create_handler failed",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "nan_deinit");
  v17 = wlan_objmgr_unregister_psoc_destroy_handler(
          0xFu,
          (__int64)nan_psoc_obj_destroyed_notification,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16);
  if ( v17 )
  {
    v26 = v17;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: wlan_objmgr_deregister_psoc_destroy_handler failed",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "nan_deinit");
    handler = v26;
  }
  v27 = wlan_objmgr_unregister_vdev_create_handler(
          0xFu,
          (__int64)nan_vdev_obj_created_notification,
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
    v36 = v27;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: wlan_objmgr_unregister_psoc_create_handler failed",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "nan_deinit");
    handler = v36;
  }
  v37 = wlan_objmgr_unregister_vdev_destroy_handler(
          0xFu,
          (__int64)nan_vdev_obj_destroyed_notification,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35);
  if ( v37 )
  {
    v46 = v37;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: wlan_objmgr_deregister_psoc_destroy_handler failed",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "nan_deinit");
    handler = v46;
  }
  v47 = wlan_objmgr_unregister_peer_create_handler(
          0xFu,
          (__int64)nan_peer_obj_created_notification,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45);
  if ( v47 )
  {
    v56 = v47;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: wlan_objmgr_unregister_peer_create_handler failed",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "nan_deinit");
    handler = v56;
  }
  v57 = wlan_objmgr_unregister_peer_destroy_handler(
          0xFu,
          (__int64)nan_peer_obj_destroyed_notification,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55);
  if ( v57 )
  {
    v66 = v57;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: wlan_objmgr_deregister_peer_destroy_handler failed",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "nan_deinit");
    return v66;
  }
  return handler;
}
