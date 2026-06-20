__int64 cleanup_module()
{
  platform_driver_unregister(msm_eud_driver);
  return uart_unregister_driver(&eud_uart_driver);
}
