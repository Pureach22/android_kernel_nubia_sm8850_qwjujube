__int64 mlme_register_mlme_ext_ops()
{
  mlme_set_ops_register_cb(mlme_get_global_ops);
  return 0;
}
