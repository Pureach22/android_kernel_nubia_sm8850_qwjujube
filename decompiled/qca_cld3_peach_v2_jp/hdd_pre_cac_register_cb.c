__int64 hdd_pre_cac_register_cb()
{
  __int64 v0; // x0

  v0 = osif_pre_cac_set_legacy_cb(pre_cac_legacy_ops);
  return osif_pre_cac_register_cb(v0);
}
