__int64 osif_pre_cac_register_cb()
{
  ucfg_pre_cac_set_osif_cb((__int64)pre_cac_ops);
  return 0;
}
