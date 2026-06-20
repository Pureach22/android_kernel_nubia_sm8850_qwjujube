__int64 init_module()
{
  return _platform_driver_register(audio_pkt_core_platform_driver, &_this_module);
}
