__int64 sub_299F84()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A0F58);
  return wlan_mlme_get_wmm_mean_data_rate_ac_bk();
}
