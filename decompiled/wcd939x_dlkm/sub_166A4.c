__int64 sub_166A4()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x10C10);
  return wcd939x_mbhc_request_micbias();
}
