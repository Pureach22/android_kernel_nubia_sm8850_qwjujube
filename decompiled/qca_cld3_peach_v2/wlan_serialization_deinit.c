__int64 __fastcall wlan_serialization_deinit(
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
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  handler = wlan_objmgr_unregister_psoc_create_handler(
              2u,
              (__int64)wlan_serialization_psoc_create_handler,
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
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: unreg fail for psoc ser obj create notf:%d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_serialization_deinit",
      handler);
    v17 = 16;
  }
  else
  {
    v17 = 0;
  }
  v18 = wlan_objmgr_unregister_psoc_destroy_handler(
          2u,
          (__int64)wlan_serialization_psoc_destroy_handler,
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
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: unreg fail for psoc ser obj destroy notf:%d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_serialization_deinit",
      v18);
    v17 = 16;
  }
  v27 = wlan_objmgr_unregister_pdev_create_handler(
          2u,
          (__int64)wlan_serialization_pdev_create_handler,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26);
  if ( v27 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: unreg fail for pdev ser obj create notf:%d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_serialization_deinit",
      v27);
    v17 = 16;
  }
  v36 = wlan_objmgr_unregister_pdev_destroy_handler(
          2u,
          (__int64)wlan_serialization_pdev_destroy_handler,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35);
  if ( v36 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: unreg fail for pdev ser destroy notf:%d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_serialization_deinit",
      v36);
    v17 = 16;
  }
  qdf_trace_msg(
    0x4Cu,
    8u,
    "%s: deregistered callbacks with obj mgr successfully",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "wlan_serialization_deinit");
  return v17;
}
