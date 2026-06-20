__int64 sub_2CAA1C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D19F0);
  return wlan_mlme_get_wmm_mean_data_rate_ac_vi();
}
