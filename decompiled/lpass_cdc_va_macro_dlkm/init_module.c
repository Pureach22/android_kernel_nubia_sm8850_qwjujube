__int64 init_module()
{
  return _platform_driver_register(lpass_cdc_va_macro_driver, &_this_module);
}
