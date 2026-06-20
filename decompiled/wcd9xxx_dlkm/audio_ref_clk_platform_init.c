__int64 audio_ref_clk_platform_init()
{
  return _platform_driver_register(audio_ref_clk_driver, &_this_module);
}
