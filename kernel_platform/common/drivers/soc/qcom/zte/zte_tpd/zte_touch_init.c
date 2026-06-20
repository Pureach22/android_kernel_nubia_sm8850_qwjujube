// Alternative name is 'init_module'
int zte_touch_init(void)
{
  printk(unk_3CEA5, "zte_touch_init", 0L);
  return _platform_driver_register(&zte_touch_device_driver, THIS_MODULE);
}
module_init(zte_touch_init);

