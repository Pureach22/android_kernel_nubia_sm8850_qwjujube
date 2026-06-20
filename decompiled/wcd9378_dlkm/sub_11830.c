__int64 sub_11830()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xB53C);
  return wcd9378_mbhc_deinit();
}
