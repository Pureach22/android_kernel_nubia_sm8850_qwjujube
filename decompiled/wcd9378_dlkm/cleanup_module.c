__int64 cleanup_module()
{
  return platform_driver_unregister(wcd9378_codec_driver);
}
