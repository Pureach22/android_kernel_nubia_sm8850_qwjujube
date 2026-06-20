__int64 sub_10E3C()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xAB48);
  return wcd938x_mbhc_deinit();
}
