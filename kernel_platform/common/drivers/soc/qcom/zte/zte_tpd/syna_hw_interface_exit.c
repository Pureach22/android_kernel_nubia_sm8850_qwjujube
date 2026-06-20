__int64 syna_hw_interface_exit(void)
{
  spi_unregister_driver(&syna_spi_driver);
  if ( p_device )
  {
    platform_device_unregister((struct platform_device *)p_device);
    p_device = 0;
  }
  return 0;
}
