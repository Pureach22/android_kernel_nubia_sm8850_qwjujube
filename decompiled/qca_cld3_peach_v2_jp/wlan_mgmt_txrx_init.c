__int64 wlan_mgmt_txrx_init()
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
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  handler = wlan_objmgr_register_psoc_create_handler(1, wlan_mgmt_txrx_psoc_obj_create_notification, 0);
  if ( handler )
  {
    v9 = handler;
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Failed to register mgmt txrx psoc create handler",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "wlan_mgmt_txrx_init");
  }
  else
  {
    v10 = wlan_objmgr_register_psoc_destroy_handler(1, wlan_mgmt_txrx_psoc_obj_destroy_notification, 0);
    if ( v10 )
    {
      v9 = v10;
      qdf_trace_msg(
        0x4Bu,
        2u,
        "%s: Failed to register mgmt txrx psoc destroy handler",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_mgmt_txrx_init");
    }
    else
    {
      v19 = wlan_objmgr_register_pdev_create_handler(1, wlan_mgmt_txrx_pdev_obj_create_notification, 0);
      if ( v19 )
      {
        v9 = v19;
        qdf_trace_msg(
          0x4Bu,
          2u,
          "%s: Failed to register mgmt txrx pdev obj create handler",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_mgmt_txrx_init");
      }
      else
      {
        v9 = wlan_objmgr_register_pdev_destroy_handler(1, wlan_mgmt_txrx_pdev_obj_destroy_notification, 0);
        if ( !v9 )
        {
          qdf_trace_msg(
            0x4Bu,
            8u,
            "%s: Successfully registered create and destroy handlers with objmgr",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wlan_mgmt_txrx_init");
          return v9;
        }
        qdf_trace_msg(
          0x4Bu,
          2u,
          "%s: Failed to register mgmt txrx obj destroy handler",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "wlan_mgmt_txrx_init");
        wlan_objmgr_unregister_pdev_create_handler(1, wlan_mgmt_txrx_pdev_obj_create_notification, 0);
      }
      wlan_objmgr_unregister_psoc_destroy_handler(1, wlan_mgmt_txrx_psoc_obj_destroy_notification, 0);
    }
    wlan_objmgr_unregister_psoc_create_handler(1, wlan_mgmt_txrx_psoc_obj_create_notification, 0);
  }
  return v9;
}
