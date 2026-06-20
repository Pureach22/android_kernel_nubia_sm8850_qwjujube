__int64 init_module()
{
  return _platform_driver_register(spi_geni_driver, &_this_module);
}
