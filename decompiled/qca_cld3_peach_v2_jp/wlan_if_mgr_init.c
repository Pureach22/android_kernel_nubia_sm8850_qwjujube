__int64 wlan_if_mgr_init()
{
  unsigned int handler; // w0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  unsigned int v9; // w19
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19

  handler = wlan_objmgr_register_psoc_create_handler(38, wlan_if_mgr_psoc_created_notification, 0);
  if ( handler )
  {
    v9 = handler;
    qdf_trace_msg(
      0x78u,
      2u,
      "%s: Failed to register psoc create handler",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "wlan_if_mgr_init");
    return v9;
  }
  else
  {
    v11 = wlan_objmgr_register_psoc_destroy_handler(38, wlan_if_mgr_psoc_destroyed_notification, 0);
    if ( v11 )
    {
      v20 = v11;
      qdf_trace_msg(
        0x78u,
        2u,
        "%s: Failed to create psoc delete handler",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_if_mgr_init");
      wlan_objmgr_unregister_psoc_create_handler(38, wlan_if_mgr_psoc_created_notification, 0);
      return v20;
    }
    else
    {
      qdf_trace_msg(
        0x78u,
        8u,
        "%s: interface mgr psoc create and delete handler registered with objmgr",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_if_mgr_init");
      return 0;
    }
  }
}
