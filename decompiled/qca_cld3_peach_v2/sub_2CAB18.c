__int64 sub_2CAB18()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D1AEC);
  return wlan_mlme_get_wmm_uapsd_vi_srv_intv();
}
