__int64 sub_14EDC()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xEBE8);
  return wcd939x_mbhc_hs_detect_exit();
}
