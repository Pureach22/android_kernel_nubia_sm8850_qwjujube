__int64 sub_299AE4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0AB8);
  return wlan_mlme_get_wmm_mean_data_rate_ac_vi();
}
