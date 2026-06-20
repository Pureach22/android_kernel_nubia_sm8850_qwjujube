__int64 osif_cm_register_cb()
{
  mlme_set_osif_cm_cb(osif_cm_get_global_ops);
  return 0;
}
