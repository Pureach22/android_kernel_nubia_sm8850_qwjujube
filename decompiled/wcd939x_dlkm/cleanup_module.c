__int64 cleanup_module()
{
  return platform_driver_unregister(wcd939x_codec_driver);
}
