__int64 sub_9104()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x3670);
  return wcd938x_mbhc_micb_adjust_voltage();
}
