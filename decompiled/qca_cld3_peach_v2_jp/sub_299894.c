__int64 sub_299894()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0868);
  return wlan_mlme_get_wmm_uapsd_vo_srv_intv();
}
