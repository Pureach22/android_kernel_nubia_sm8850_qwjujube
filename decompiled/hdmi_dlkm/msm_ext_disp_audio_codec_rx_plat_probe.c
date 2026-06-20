__int64 __fastcall msm_ext_disp_audio_codec_rx_plat_probe(__int64 a1)
{
  return snd_soc_register_component(a1 + 16, &msm_ext_disp_codec_rx_driver, &msm_ext_disp_audio_codec_rx_dais, 4);
}
