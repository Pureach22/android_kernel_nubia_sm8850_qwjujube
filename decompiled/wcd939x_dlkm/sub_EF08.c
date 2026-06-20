__int64 sub_EF08()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0x8C14);
  return wcd939x_soc_codec_remove();
}
