__int64 init_module()
{
  unsigned int v0; // w20

  printk(&unk_9DD2, "qbt_handler_init");
  v0 = _platform_driver_register(qbt_plat_driver, &_this_module);
  printk(&unk_9ABB, "qbt_handler_init");
  return v0;
}
