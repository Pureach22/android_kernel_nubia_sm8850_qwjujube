__int64 __fastcall wlan_twt_deinit(
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
  __int64 result; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w19

  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(
                       0x2Cu,
                       (__int64)wlan_twt_psoc_obj_create_handler,
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8) )
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Failed to unregister psoc create handler",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_twt_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(
                       0x2Cu,
                       (__int64)wlan_twt_psoc_obj_destroy_handler,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Failed to unregister psoc destroy handler",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_twt_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_vdev_create_handler(
                       0x2Cu,
                       (__int64)wlan_twt_vdev_obj_create_handler,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Failed to unregister vdev create handler",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_twt_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_vdev_destroy_handler(
                       0x2Cu,
                       (__int64)wlan_twt_vdev_obj_destroy_handler,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31) )
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Failed to unregister vdev destroy handler",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wlan_twt_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_peer_create_handler(
                       0x2Cu,
                       (__int64)wlan_twt_peer_obj_create_handler,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       v39) )
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Failed to unregister peer create handler",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wlan_twt_deinit");
  result = wlan_objmgr_unregister_peer_destroy_handler(
             0x2Cu,
             (__int64)wlan_twt_peer_obj_destroy_handler,
             v40,
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47);
  if ( (_DWORD)result )
  {
    v57 = result;
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Failed to unregister peer destroy handler",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "wlan_twt_deinit");
    return v57;
  }
  return result;
}
