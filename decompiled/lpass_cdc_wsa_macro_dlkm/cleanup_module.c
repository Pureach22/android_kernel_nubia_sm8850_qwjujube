__int64 cleanup_module()
{
  return platform_driver_unregister(lpass_cdc_wsa_macro_driver);
}
