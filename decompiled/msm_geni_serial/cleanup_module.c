__int64 cleanup_module()
{
  platform_driver_unregister(msm_geni_serial_platform_driver);
  return uart_unregister_driver(&msm_geni_serial_hs_driver);
}
