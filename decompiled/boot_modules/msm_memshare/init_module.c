__int64 init_module()
{
  return _platform_driver_register(&memshare_pdriver, &_this_module);
}
