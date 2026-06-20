__int64 sub_2CA7CC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D17A0);
  return wlan_mlme_get_wmm_uapsd_vo_srv_intv();
}
