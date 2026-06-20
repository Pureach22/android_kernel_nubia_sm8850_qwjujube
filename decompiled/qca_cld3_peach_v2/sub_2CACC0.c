__int64 sub_2CACC0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D1C94);
  return wlan_mlme_get_wmm_min_phy_rate_ac_be();
}
