__int64 syna_hw_interface_exit()
{
  driver_unregister(&off_B28);
  return platform_device_unregister(&syna_spi_device);
}
