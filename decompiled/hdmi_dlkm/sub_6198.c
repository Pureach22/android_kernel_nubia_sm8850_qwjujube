__int64 sub_6198()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xFFFFFFFFFFFFFEA4LL);
  return msm_ext_disp_audio_codec_rx_remove();
}
