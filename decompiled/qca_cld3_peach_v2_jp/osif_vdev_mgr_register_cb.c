__int64 osif_vdev_mgr_register_cb()
{
  mlme_set_osif_vdev_mgr_cb(osif_vdev_mgr_get_global_ops);
  return 0;
}
