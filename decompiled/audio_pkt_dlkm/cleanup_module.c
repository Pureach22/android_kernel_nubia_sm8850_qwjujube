__int64 cleanup_module()
{
  return platform_driver_unregister(audio_pkt_core_platform_driver);
}
