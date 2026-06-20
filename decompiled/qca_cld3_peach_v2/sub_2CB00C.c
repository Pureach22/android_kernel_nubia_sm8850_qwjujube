__int64 sub_2CB00C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D1FE0);
  return wlan_mlme_get_wmm_uapsd_bk_sus_intv();
}
