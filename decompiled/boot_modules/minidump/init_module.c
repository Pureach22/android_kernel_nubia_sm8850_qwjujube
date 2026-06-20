__int64 init_module()
{
  return _platform_driver_register(&msm_minidump_smem_driver, &_this_module);
}
