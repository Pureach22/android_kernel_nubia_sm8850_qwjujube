__int64 sub_B104()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x5670);
  return wcd939x_mbhc_micb_adjust_voltage();
}
