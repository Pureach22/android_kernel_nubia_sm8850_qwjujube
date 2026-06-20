__int64 __fastcall wlan_eht_chan_phy_mode(__int64 a1, __int16 a2, int a3)
{
  unsigned int v5; // w9
  unsigned int v7; // w8

  if ( (wlan_reg_is_24ghz_ch_freq(a1) & 1) != 0 )
  {
    if ( a2 == 40 )
      v5 = 36;
    else
      v5 = 0;
    if ( a2 == 20 )
      return 32;
    else
      return v5;
  }
  else
  {
    switch ( a2 )
    {
      case 20:
        return 31;
      case 80:
        return 37;
      case 40:
        return 33;
      default:
        if ( a3 == 7 )
          v7 = 40;
        else
          v7 = 0;
        if ( a3 == 3 )
          return 39;
        else
          return v7;
    }
  }
}
