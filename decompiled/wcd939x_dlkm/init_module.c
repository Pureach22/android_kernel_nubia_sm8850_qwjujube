__int64 init_module()
{
  return _platform_driver_register(wcd939x_codec_driver, &_this_module);
}
