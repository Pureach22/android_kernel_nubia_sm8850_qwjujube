__int64 __fastcall wma_eht_chan_phy_mode(unsigned int a1, char a2, __int16 a3, int a4)
{
  unsigned int v6; // w9
  unsigned int v8; // w8

  if ( (a2 & 0xFE) != 0xC )
    return 0;
  if ( wlan_reg_is_24ghz_ch_freq(a1) )
  {
    if ( a3 == 40 )
      v6 = 36;
    else
      v6 = 0;
    if ( a3 == 20 )
      return 32;
    else
      return v6;
  }
  else
  {
    switch ( a3 )
    {
      case 20:
        return 31;
      case 80:
        return 37;
      case 40:
        return 33;
      default:
        if ( a4 == 7 )
          v8 = 40;
        else
          v8 = 0;
        if ( a4 == 3 )
          return 39;
        else
          return v8;
    }
  }
}
