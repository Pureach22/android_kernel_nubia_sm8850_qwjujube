// Alternative name is 'init_module'
__int64 __fastcall zte_touch_init(__int64 a1, __int64 a2, __int64 a3)
{
  printk(&unk_3CEA5, "zte_touch_init", a3);
  return _platform_driver_register(zte_touch_device_driver, &_this_module);
}
