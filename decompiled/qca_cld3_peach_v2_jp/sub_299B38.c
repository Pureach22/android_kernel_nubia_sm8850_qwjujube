__int64 sub_299B38()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0B0C);
  return wlan_mlme_get_wmm_min_phy_rate_ac_vi();
}
