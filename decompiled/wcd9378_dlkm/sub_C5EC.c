__int64 sub_C5EC()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0x62F8);
  return wcd9378_soc_codec_remove();
}
