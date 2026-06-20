__int64 __fastcall wlan_populate_band_bitmap(unsigned __int16 **a1)
{
  __int64 v2; // x21
  __int64 v3; // x9

  v2 = 1LL << wlan_reg_freq_to_band(*a1[4]);
  v3 = 1LL << wlan_reg_freq_to_band(*a1[10]);
  return (unsigned int)v2 | (unsigned int)v3 | (unsigned int)(1LL << wlan_reg_freq_to_band(*a1[16]));
}
