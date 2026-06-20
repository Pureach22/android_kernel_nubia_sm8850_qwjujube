__int64 _wlan_crypto_init()
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

  qdf_mutex_create((__int64)&crypto_lock);
  handler = wlan_objmgr_register_psoc_create_handler(14, wlan_crypto_psoc_obj_create_handler, 0);
  if ( !handler )
  {
    v9 = wlan_objmgr_register_vdev_create_handler(14, wlan_crypto_vdev_obj_create_handler, 0);
    if ( !v9 )
    {
      v9 = wlan_objmgr_register_peer_create_handler(14, wlan_crypto_peer_obj_create_handler, 0);
      if ( !v9 )
      {
        v10 = wlan_objmgr_register_psoc_destroy_handler(14, wlan_crypto_psoc_obj_destroy_handler, 0);
        if ( v10 )
        {
          v9 = v10;
          qdf_trace_msg(
            0x1Cu,
            2u,
            "%s: psoc destroy failure",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "__wlan_crypto_init");
        }
        else
        {
          v9 = wlan_objmgr_register_vdev_destroy_handler(14, wlan_crypto_vdev_obj_destroy_handler, 0);
          if ( !v9 )
          {
            v9 = wlan_objmgr_register_peer_destroy_handler(14, wlan_crypto_peer_obj_destroy_handler, 0);
            if ( !v9 )
              return v9;
            wlan_objmgr_unregister_vdev_destroy_handler(14, wlan_crypto_vdev_obj_destroy_handler, 0);
          }
          wlan_objmgr_unregister_psoc_destroy_handler(14, wlan_crypto_psoc_obj_destroy_handler, 0);
        }
        wlan_objmgr_unregister_peer_create_handler(14, wlan_crypto_peer_obj_create_handler, 0);
      }
      wlan_objmgr_unregister_vdev_create_handler(14, wlan_crypto_vdev_obj_create_handler, 0);
    }
    wlan_objmgr_unregister_psoc_create_handler(14, wlan_crypto_psoc_obj_create_handler, 0);
    return v9;
  }
  v9 = handler;
  qdf_trace_msg(0x1Cu, 2u, "%s: psoc creation failure", v1, v2, v3, v4, v5, v6, v7, v8, "__wlan_crypto_init");
  return v9;
}
