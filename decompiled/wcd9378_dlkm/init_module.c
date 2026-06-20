__int64 init_module()
{
  return _platform_driver_register(wcd9378_codec_driver, &_this_module);
}
