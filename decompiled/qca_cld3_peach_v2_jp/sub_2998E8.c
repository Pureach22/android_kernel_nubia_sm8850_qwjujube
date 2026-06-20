__int64 sub_2998E8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A08BC);
  return wlan_mlme_get_wmm_uapsd_vo_sus_intv();
}
