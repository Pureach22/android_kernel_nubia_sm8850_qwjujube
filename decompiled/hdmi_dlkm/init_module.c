__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _platform_driver_register(msm_ext_disp_audio_codec_rx_driver, &_this_module);
  if ( v0 )
    printk(&unk_84E7, "msm_ext_disp_audio_codec_rx_init", v0);
  return v0;
}
