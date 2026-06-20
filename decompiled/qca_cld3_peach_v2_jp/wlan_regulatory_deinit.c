__int64 __fastcall wlan_regulatory_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  unsigned int v8; // w19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int handler; // w0
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

  v8 = wlan_objmgr_unregister_pdev_destroy_handler(
         0xDu,
         (__int64)wlan_regulatory_pdev_obj_destroyed_notification,
         a1,
         a2,
         a3,
         a4,
         a5,
         a6,
         a7,
         a8);
  if ( v8 )
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: failed to unregister reg pdev obj destroy handler",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_regulatory_deinit");
  handler = wlan_objmgr_unregister_pdev_create_handler(
              0xDu,
              (__int64)&wlan_regulatory_pdev_obj_created_notification,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16);
  if ( handler )
  {
    v26 = handler;
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: failed to unregister reg pdev obj create handler",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_regulatory_deinit");
    v8 = v26;
  }
  v27 = wlan_objmgr_unregister_psoc_destroy_handler(
          0xDu,
          (__int64)wlan_regulatory_psoc_obj_destroyed_notification,
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
      0x51u,
      2u,
      "%s: failed to unregister reg psoc obj destroy handler",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_regulatory_deinit");
    v8 = v36;
  }
  v37 = wlan_objmgr_unregister_psoc_create_handler(
          0xDu,
          (__int64)wlan_regulatory_psoc_obj_created_notification,
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
      0x51u,
      2u,
      "%s: failed to unregister reg psoc obj create handler",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_regulatory_deinit");
    v8 = v46;
  }
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: deregistered callbacks with obj mgr",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "wlan_regulatory_deinit");
  return v8;
}
