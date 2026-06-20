__int64 sub_10B2C()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xA838);
  return wcd938x_mbhc_hs_detect_exit();
}
