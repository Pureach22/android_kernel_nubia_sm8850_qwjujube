__int64 __fastcall wlan_nan_sap_override_freq(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int channel; // w20
  unsigned int v6; // w21

  if ( !policy_mgr_is_vdev_ll_lt_sap(a1, a2) )
  {
    channel = policy_mgr_mode_specific_get_channel(a1, 5);
    if ( (policy_mgr_is_non_ml_sta_present(a1) & 1) != 0 && (policy_mgr_is_mlo_sta_present(a1) & 1) == 0 )
    {
      v6 = policy_mgr_mode_specific_get_channel(a1, 0);
      if ( wlan_reg_is_24ghz_ch_freq(v6) )
        channel = v6;
    }
    if ( channel )
      return channel;
  }
  return a3;
}
