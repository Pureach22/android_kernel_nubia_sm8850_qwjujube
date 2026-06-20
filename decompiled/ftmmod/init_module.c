__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19

  printk(&unk_673A, "ftm_init");
  v0 = platform_device_register(&ftm_dev);
  if ( v0 )
  {
    printk(&unk_67D0, v0);
    return (unsigned int)-19;
  }
  else
  {
    v1 = _platform_driver_probe(&ftm_driver, ftm_probe, &_this_module);
    if ( v1 )
      printk(&unk_674E, v1);
    else
      printk(&unk_66B5, "ftm_init");
  }
  return v1;
}
