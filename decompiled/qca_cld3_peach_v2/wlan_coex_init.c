__int64 __fastcall wlan_coex_init(
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
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  handler = wlan_objmgr_register_psoc_create_handler(
              0x21u,
              (__int64)wlan_coex_psoc_created_notification,
              0,
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
    v17 = handler;
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: Failed to register psoc create handler",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_coex_init");
    return v17;
  }
  else
  {
    v19 = wlan_objmgr_register_psoc_destroy_handler(
            0x21u,
            (__int64)wlan_coex_psoc_destroyed_notification,
            0,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16);
    if ( v19 )
    {
      v28 = v19;
      qdf_trace_msg(
        0x70u,
        2u,
        "%s: Failed to create psoc delete handler",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wlan_coex_init");
      wlan_objmgr_unregister_psoc_create_handler(
        0x21u,
        (__int64)wlan_coex_psoc_created_notification,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36);
      return v28;
    }
    else
    {
      qdf_trace_msg(
        0x70u,
        8u,
        "%s: coex psoc create and delete handler registered",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wlan_coex_init");
      return 0;
    }
  }
}
