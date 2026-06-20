__int64 sub_BAAC()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x6018);
  return wcd939x_codec_force_enable_micbias_v2();
}
