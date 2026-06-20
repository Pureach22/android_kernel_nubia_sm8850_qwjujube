__int64 kgsl_mmu_exit()
{
  return platform_driver_unregister(kgsl_mmu_driver);
}
