__int64 sub_9B28()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0x3834);
  return lpass_cdc_soc_codec_remove();
}
