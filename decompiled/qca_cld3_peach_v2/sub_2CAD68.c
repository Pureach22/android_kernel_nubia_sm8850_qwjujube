__int64 sub_2CAD68()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D1D3C);
  return wlan_mlme_get_wmm_uapsd_be_srv_intv();
}
