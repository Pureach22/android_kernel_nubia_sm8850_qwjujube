__int64 sub_2CAFB8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D1F8C);
  return wlan_mlme_get_wmm_uapsd_bk_srv_intv();
}
