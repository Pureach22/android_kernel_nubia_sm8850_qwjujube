__int64 cleanup_module()
{
  return platform_driver_unregister(msm_ext_disp_audio_codec_rx_driver);
}
