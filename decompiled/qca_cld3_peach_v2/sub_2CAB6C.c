__int64 sub_2CAB6C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D1B40);
  return wlan_mlme_get_wmm_uapsd_vi_sus_intv();
}
