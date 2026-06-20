__int64 __fastcall msm_ext_disp_audio_codec_rx_plat_remove(__int64 a1)
{
  return snd_soc_unregister_component(a1 + 16);
}
