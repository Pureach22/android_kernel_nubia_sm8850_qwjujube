__int64 sub_2CA820()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D17F4);
  return wlan_mlme_get_wmm_uapsd_vo_sus_intv();
}
