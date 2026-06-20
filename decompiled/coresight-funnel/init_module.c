__int64 init_module()
{
  unsigned int v0; // w19
  unsigned int v1; // w0

  v0 = funnel_pm_setup();
  if ( !v0 )
  {
    v1 = _platform_driver_register(funnel_driver, &_this_module);
    if ( v1 )
    {
      v0 = v1;
      printk(&unk_7860);
    }
    else
    {
      v0 = _amba_driver_register(&dynamic_funnel_driver, &_this_module);
      if ( !v0 )
        return v0;
      printk(&unk_78EE);
      platform_driver_unregister(funnel_driver);
    }
    funnel_pm_clear();
  }
  return v0;
}
