__int64 cleanup_module()
{
  return platform_driver_unregister(lpass_cdc_va_macro_driver);
}
