__int64 sub_299D88()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0D5C);
  return wlan_mlme_get_wmm_min_phy_rate_ac_be();
}
