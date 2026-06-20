__int64 audio_ref_clk_platform_exit()
{
  return platform_driver_unregister(audio_ref_clk_driver);
}
