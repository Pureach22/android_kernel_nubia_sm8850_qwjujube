__int64 sub_2CA724()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D16F8);
  return wlan_mlme_get_wmm_min_phy_rate_ac_vo();
}
