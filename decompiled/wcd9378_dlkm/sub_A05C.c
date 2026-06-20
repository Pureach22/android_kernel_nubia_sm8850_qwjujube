__int64 sub_A05C()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x45C8);
  return wcd9378_mbhc_micb_adjust_voltage();
}
