__int64 init_module()
{
  unsigned int v0; // w19
  unsigned int v1; // w0

  v0 = replicator_pm_setup();
  if ( !v0 )
  {
    v1 = _platform_driver_register(replicator_driver, &_this_module);
    if ( v1 )
    {
      v0 = v1;
      printk(&unk_7B2A);
    }
    else
    {
      v0 = _amba_driver_register(&dynamic_replicator_driver, &_this_module);
      if ( !v0 )
        return v0;
      printk(&unk_7BF8);
      platform_driver_unregister(replicator_driver);
    }
    replicator_pm_clear();
  }
  return v0;
}
