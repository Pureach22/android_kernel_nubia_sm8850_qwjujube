__int64 cleanup_module()
{
  return platform_driver_unregister(lpass_cdc_tx_macro_driver);
}
