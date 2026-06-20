__int64 cleanup_module()
{
  platform_driver_unregister(adreno_platform_driver);
  gmu_core_unregister();
  kgsl_mmu_exit();
  return kgsl_core_exit();
}
