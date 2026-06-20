__int64 sub_29A080()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A1054);
  return wlan_mlme_get_wmm_uapsd_bk_srv_intv();
}
