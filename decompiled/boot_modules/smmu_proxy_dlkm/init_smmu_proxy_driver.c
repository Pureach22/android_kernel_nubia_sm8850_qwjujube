// Alternative name is 'init_module'
__int64 init_smmu_proxy_driver()
{
  return _platform_driver_register(&smmu_proxy_driver, &_this_module);
}
