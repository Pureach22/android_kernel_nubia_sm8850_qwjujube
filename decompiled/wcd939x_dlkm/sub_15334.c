__int64 sub_15334()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xF040);
  return wcd939x_mbhc_deinit();
}
