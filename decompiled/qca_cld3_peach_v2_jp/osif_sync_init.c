__int64 osif_sync_init()
{
  osif_driver_sync_init();
  osif_psoc_sync_init();
  return osif_vdev_sync_init();
}
