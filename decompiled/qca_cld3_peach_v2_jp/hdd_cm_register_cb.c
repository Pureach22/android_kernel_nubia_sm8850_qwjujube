__int64 hdd_cm_register_cb()
{
  osif_cm_set_legacy_cb((__int64)osif_ops_0);
  return osif_cm_register_cb();
}
