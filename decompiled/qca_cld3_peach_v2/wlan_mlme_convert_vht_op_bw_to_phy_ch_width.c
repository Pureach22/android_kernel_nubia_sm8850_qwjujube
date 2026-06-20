__int64 __fastcall wlan_mlme_convert_vht_op_bw_to_phy_ch_width(
        unsigned __int8 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4)
{
  int v4; // w8
  int v6; // w8

  if ( a1 > 1u )
  {
    if ( a1 == 2 )
      return 3;
    return a1 == 3;
  }
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( !a4 )
        return 2;
      v4 = a4 - a3;
      if ( v4 < 0 )
        v4 = a3 - a4;
      if ( v4 != 8 )
        return 2;
      return 3;
    }
    return 0;
  }
  v6 = a3 - a2;
  if ( v6 < 0 )
    v6 = a2 - a3;
  return v6 == 2;
}
