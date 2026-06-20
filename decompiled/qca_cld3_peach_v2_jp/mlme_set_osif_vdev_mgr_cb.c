void *__fastcall mlme_set_osif_vdev_mgr_cb(void *result)
{
  glbl_vdev_mgr_ops_cb = result;
  return result;
}
