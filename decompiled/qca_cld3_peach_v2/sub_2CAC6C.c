__int64 sub_2CAC6C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D1C40);
  return wlan_mlme_get_wmm_mean_data_rate_ac_be();
}
