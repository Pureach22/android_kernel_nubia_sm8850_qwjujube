// Alternative name is 'init_module'
__int64 __fastcall zte_misc_init(__int64 a1, __int64 a2, __int64 a3)
{
  printk(&unk_7F2F, "zte_misc_init", a3);
  return _platform_driver_register(zte_misc_device_driver, &_this_module);
}
