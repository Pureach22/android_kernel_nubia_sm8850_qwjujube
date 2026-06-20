__int64 cleanup_module()
{
  return platform_driver_unregister(lpass_cdc_wsa2_macro_driver);
}
