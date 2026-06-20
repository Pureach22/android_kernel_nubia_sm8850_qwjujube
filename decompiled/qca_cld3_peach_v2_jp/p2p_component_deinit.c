__int64 __fastcall p2p_component_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
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

  handler = wlan_objmgr_unregister_vdev_create_handler(
              5u,
              (__int64)p2p_vdev_obj_create_notification,
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
      0x4Eu,
      2u,
      "%s: Failed to unregister p2p vdev create handler, %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "p2p_component_deinit",
      handler);
  v17 = wlan_objmgr_unregister_vdev_destroy_handler(
          5u,
          (__int64)p2p_vdev_obj_destroy_notification,
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
      0x4Eu,
      2u,
      "%s: Failed to unregister p2p vdev delete handler, %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "p2p_component_deinit",
      v17);
    handler = v26;
  }
  v27 = wlan_objmgr_unregister_psoc_create_handler(
          5u,
          (__int64)p2p_psoc_obj_create_notification,
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
      0x4Eu,
      2u,
      "%s: Failed to unregister p2p obj create handler, %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "p2p_component_deinit",
      v27);
    handler = v36;
  }
  v37 = wlan_objmgr_unregister_psoc_destroy_handler(
          5u,
          (__int64)p2p_psoc_obj_destroy_notification,
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
      0x4Eu,
      2u,
      "%s: Failed to unregister p2p obj delete handler, %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "p2p_component_deinit",
      v37);
    handler = v46;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: Unregister p2p obj handler complete",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "p2p_component_deinit");
  return handler;
}
