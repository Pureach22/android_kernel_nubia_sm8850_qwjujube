__int64 sub_7110()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xE1C);
  return swr_dmic_codec_remove();
}
