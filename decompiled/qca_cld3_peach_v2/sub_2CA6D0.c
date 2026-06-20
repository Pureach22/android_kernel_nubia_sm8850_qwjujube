__int64 sub_2CA6D0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D16A4);
  return wlan_mlme_get_wmm_mean_data_rate_ac_vo();
}
