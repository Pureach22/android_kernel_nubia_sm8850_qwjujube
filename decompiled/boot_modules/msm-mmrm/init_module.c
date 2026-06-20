__int64 init_module()
{
  unsigned int v0; // w19
  int v1; // w8

  v0 = _platform_driver_register(msm_mmrm_driver, &_this_module);
  v1 = msm_mmrm_debug;
  if ( v0 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      printk(&unk_D825, "err ", "msm_mmrm_init");
      v1 = msm_mmrm_debug;
    }
    if ( (~v1 & 0x10001) == 0 )
      printk(&unk_DA62, "err ", "msm_mmrm_init");
  }
  else if ( (~msm_mmrm_debug & 0x10002) == 0 )
  {
    printk(&unk_C9DE, "high", "msm_mmrm_init");
  }
  return v0;
}
