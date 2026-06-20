__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _platform_driver_register(&microdump_driver, &_this_module);
  if ( v0 )
    printk(&unk_675D, "microdump_init");
  return v0;
}
