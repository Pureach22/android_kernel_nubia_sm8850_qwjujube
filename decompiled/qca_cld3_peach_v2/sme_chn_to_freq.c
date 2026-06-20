__int64 __fastcall sme_chn_to_freq(unsigned __int8 a1)
{
  unsigned int v2; // w20

  v2 = 0;
  while ( (unsigned __int8)wlan_reg_ch_num(v2) != a1 )
  {
    if ( ++v2 == 102 )
      return 0;
  }
  return wlan_reg_ch_to_freq(v2);
}
