__int64 init_module()
{
  return _platform_driver_register(qti_ptd_share_module, &_this_module);
}
