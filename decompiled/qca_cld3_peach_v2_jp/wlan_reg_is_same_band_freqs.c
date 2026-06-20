__int64 __fastcall wlan_reg_is_same_band_freqs(unsigned int a1, unsigned int a2)
{
  return reg_is_same_band_freqs(a1, a2) & 1;
}
