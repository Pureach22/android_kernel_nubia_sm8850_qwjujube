__int64 kgsl_mmu_init()
{
  return _platform_driver_register(kgsl_mmu_driver, &_this_module);
}
