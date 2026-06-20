__int64 init_module()
{
  __int64 v0; // x4
  unsigned int v1; // w19

  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90870, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init");
  v1 = _platform_driver_register(msm_vidc_driver, &_this_module);
  if ( v1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_96579, "err ", 0xFFFFFFFFLL, "codec", v0);
  }
  else if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_838C0, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init");
  }
  return v1;
}
