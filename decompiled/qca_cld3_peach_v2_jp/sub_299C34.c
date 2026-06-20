__int64 sub_299C34()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0C08);
  return wlan_mlme_get_wmm_uapsd_vi_sus_intv();
}
