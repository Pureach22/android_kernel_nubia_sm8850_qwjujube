__int64 init_module()
{
  return _platform_driver_register(msm_stub_driver, &_this_module);
}
