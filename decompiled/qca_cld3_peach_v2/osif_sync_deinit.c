void osif_sync_deinit()
{
  osif_vdev_sync_deinit();
  osif_psoc_sync_deinit();
  osif_driver_sync_deinit();
}
