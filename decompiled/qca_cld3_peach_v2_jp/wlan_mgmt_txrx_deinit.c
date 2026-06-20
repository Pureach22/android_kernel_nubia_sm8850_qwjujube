__int64 wlan_mgmt_txrx_deinit()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7

  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(1, wlan_mgmt_txrx_psoc_obj_create_notification, 0)
    || (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(1, wlan_mgmt_txrx_psoc_obj_destroy_notification, 0)
    || (unsigned int)wlan_objmgr_unregister_pdev_create_handler(1, wlan_mgmt_txrx_pdev_obj_create_notification, 0)
    || (unsigned int)wlan_objmgr_unregister_pdev_destroy_handler(1, wlan_mgmt_txrx_pdev_obj_destroy_notification, 0) )
  {
    return 16;
  }
  qdf_trace_msg(
    0x4Bu,
    8u,
    "%s: Successfully unregistered create and destroy handlers with objmgr",
    v0,
    v1,
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    "wlan_mgmt_txrx_deinit");
  return 0;
}
