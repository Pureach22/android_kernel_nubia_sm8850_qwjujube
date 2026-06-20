__int64 __fastcall wlan_nan_sap_override_freq(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int channel; // w21
  unsigned int v6; // w20
  unsigned int v7; // w8

  if ( !policy_mgr_is_vdev_ll_lt_sap(a1, a2) )
  {
    channel = policy_mgr_mode_specific_get_channel(a1, 5);
    v6 = policy_mgr_mode_specific_get_channel(a1, 0);
    if ( wlan_reg_is_24ghz_ch_freq(v6) )
      v7 = v6;
    else
      v7 = channel;
    if ( v7 )
      return v7;
  }
  return a3;
}
