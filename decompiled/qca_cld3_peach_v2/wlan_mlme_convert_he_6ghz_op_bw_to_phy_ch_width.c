__int64 __fastcall wlan_mlme_convert_he_6ghz_op_bw_to_phy_ch_width(
        char a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 a4)
{
  int v5; // w8

  if ( a1 == 3 )
  {
    if ( a4 )
    {
      v5 = a3 - a4;
      if ( v5 < 0 )
        v5 = a4 - a3;
      if ( (unsigned int)v5 > 8 )
        return 2;
      else
        return 3;
    }
    else
    {
      return 3;
    }
  }
  else if ( a1 == 2 )
  {
    return 2;
  }
  else
  {
    return a1 == 1;
  }
}
