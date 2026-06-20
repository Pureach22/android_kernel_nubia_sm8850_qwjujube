__int64 wlan_if_mgr_deinit()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  unsigned int v8; // w19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(38, wlan_if_mgr_psoc_created_notification, 0) )
    qdf_trace_msg(
      0x78u,
      2u,
      "%s: Failed to deregister psoc create handler",
      v0,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      "wlan_if_mgr_deinit");
  v8 = wlan_objmgr_unregister_psoc_destroy_handler(38, wlan_if_mgr_psoc_destroyed_notification, 0);
  if ( v8 )
    qdf_trace_msg(
      0x78u,
      2u,
      "%s: Failed to deregister psoc delete handler",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_if_mgr_deinit");
  qdf_trace_msg(
    0x78u,
    8u,
    "%s: interface mgr psoc create and delete handler deregistered with objmgr",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "wlan_if_mgr_deinit");
  return v8;
}
