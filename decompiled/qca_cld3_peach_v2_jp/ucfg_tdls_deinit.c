__int64 __fastcall ucfg_tdls_deinit(
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
  __int64 result; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w19

  qdf_trace_msg(0, 4u, "%s: tdls module dispatcher deinit", a1, a2, a3, a4, a5, a6, a7, a8, "ucfg_tdls_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(
                       0xAu,
                       (__int64)tdls_psoc_obj_create_notification,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to unregister psoc create handler",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ucfg_tdls_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(
                       0xAu,
                       (__int64)tdls_psoc_obj_destroy_notification,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to unregister psoc delete handler",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "ucfg_tdls_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_vdev_create_handler(
                       0xAu,
                       (__int64)tdls_vdev_obj_create_notification,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31) )
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to unregister vdev create handler",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "ucfg_tdls_deinit");
  result = wlan_objmgr_unregister_vdev_destroy_handler(
             0xAu,
             (__int64)tdls_vdev_obj_destroy_notification,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39);
  if ( (_DWORD)result )
  {
    v49 = result;
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to unregister vdev delete handler",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "ucfg_tdls_deinit");
    return v49;
  }
  return result;
}
