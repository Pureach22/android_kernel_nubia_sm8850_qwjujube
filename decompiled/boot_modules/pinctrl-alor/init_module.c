__int64 init_module()
{
  return _platform_driver_register(&alor_tlmm_driver, &_this_module);
}
