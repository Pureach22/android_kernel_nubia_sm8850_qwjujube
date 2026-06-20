__int64 cleanup_module()
{
  return platform_driver_unregister(lpi_pinctrl_driver);
}
