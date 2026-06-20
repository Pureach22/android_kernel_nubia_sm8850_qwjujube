__int64 _wlan_crypto_deinit()
{
  if ( (unsigned int)wlan_objmgr_unregister_psoc_create_handler(14, wlan_crypto_psoc_obj_create_handler, 0)
    || (unsigned int)wlan_objmgr_unregister_vdev_create_handler(14, wlan_crypto_vdev_obj_create_handler, 0)
    || (unsigned int)wlan_objmgr_unregister_peer_create_handler(14, wlan_crypto_peer_obj_create_handler, 0)
    || (unsigned int)wlan_objmgr_unregister_vdev_destroy_handler(14, wlan_crypto_vdev_obj_destroy_handler, 0)
    || (unsigned int)wlan_objmgr_unregister_peer_destroy_handler(14, wlan_crypto_peer_obj_destroy_handler, 0)
    || (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(14, wlan_crypto_psoc_obj_destroy_handler, 0) )
  {
    return 16;
  }
  qdf_mutex_destroy((__int64)&crypto_lock);
  return 0;
}
