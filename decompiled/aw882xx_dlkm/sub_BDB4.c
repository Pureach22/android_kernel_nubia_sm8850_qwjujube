__int64 sub_BDB4()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0x5AC0);
  return aw882xx_codec_remove();
}
