__int64 cleanup_module()
{
  return platform_driver_unregister(lpass_cdc_rx_macro_driver);
}
