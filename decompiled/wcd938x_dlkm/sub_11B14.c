__int64 sub_11B14()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0xC080);
  return wcd938x_mbhc_request_micbias();
}
