__int64 init_module()
{
  return _platform_driver_register(wcd938x_codec_driver, &_this_module);
}
