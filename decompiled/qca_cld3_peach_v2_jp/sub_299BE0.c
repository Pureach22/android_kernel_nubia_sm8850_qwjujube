__int64 sub_299BE0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0BB4);
  return wlan_mlme_get_wmm_uapsd_vi_srv_intv();
}
