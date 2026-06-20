__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _platform_driver_register(&smp2p_sleepstate_driver, &_this_module);
  if ( v0 )
    printk(&unk_64E2);
  return v0;
}
