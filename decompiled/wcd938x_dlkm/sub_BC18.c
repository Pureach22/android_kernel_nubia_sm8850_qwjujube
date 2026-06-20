__int64 sub_BC18()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0x5924);
  return wcd938x_soc_codec_remove();
}
