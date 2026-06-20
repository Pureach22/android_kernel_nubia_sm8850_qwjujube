__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19

  v0 = _platform_driver_register(static_tpdm_driver, &_this_module);
  if ( v0 )
  {
    v1 = v0;
    printk(&unk_AA90);
  }
  else
  {
    v1 = _amba_driver_register(&tpdm_driver, &_this_module);
    if ( v1 )
    {
      printk(&unk_ACCB);
      platform_driver_unregister(static_tpdm_driver);
    }
  }
  return v1;
}
