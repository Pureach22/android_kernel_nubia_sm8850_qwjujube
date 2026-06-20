__int64 init_module()
{
  unsigned int v0; // w19

  v0 = kgsl_core_init();
  if ( !v0 )
  {
    v0 = kgsl_mmu_init();
    if ( !v0 )
    {
      gmu_core_register();
      v0 = _platform_driver_register(adreno_platform_driver, &_this_module);
      if ( !v0 )
        return v0;
      gmu_core_unregister();
      kgsl_mmu_exit();
    }
    kgsl_core_exit();
  }
  return v0;
}
