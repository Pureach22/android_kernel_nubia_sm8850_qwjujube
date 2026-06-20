__int64 init_module()
{
  __int64 v0; // x2
  unsigned int v1; // w19

  v1 = _platform_driver_register(&msm_sharedmem_driver, &_this_module);
  if ( v1 )
    printk(&unk_6973, "msm_sharedmem_init", v0);
  return v1;
}
