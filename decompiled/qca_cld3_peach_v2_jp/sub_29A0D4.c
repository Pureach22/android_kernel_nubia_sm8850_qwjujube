__int64 sub_29A0D4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A10A8);
  return wlan_mlme_get_wmm_uapsd_bk_sus_intv();
}
