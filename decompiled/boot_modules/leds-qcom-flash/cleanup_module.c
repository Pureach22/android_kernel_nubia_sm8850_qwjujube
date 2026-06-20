__int64 cleanup_module()
{
  return platform_driver_unregister(&qcom_flash_led_driver);
}
