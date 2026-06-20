__int64 sub_299E84()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0E58);
  return wlan_mlme_get_wmm_uapsd_be_sus_intv();
}
