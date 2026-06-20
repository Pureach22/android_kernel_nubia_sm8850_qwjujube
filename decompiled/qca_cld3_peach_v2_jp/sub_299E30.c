__int64 sub_299E30()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0E04);
  return wlan_mlme_get_wmm_uapsd_be_srv_intv();
}
