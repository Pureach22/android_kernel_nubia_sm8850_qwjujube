__int64 __fastcall policy_mgr_get_conc_freq_if_ml_sta_in_smm(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
{
  char v9; // w0

  if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 || (policy_mgr_is_current_hwmode_sbs(a1) & 1) != 0 )
    return 0;
  if ( wlan_reg_is_24ghz_ch_freq(a3) || wlan_reg_is_24ghz_ch_freq(a4) )
    v9 = policy_mgr_2_freq_same_mac_in_dbs(a1, a3, a2);
  else
    v9 = policy_mgr_2_freq_same_mac_in_sbs(a1, a3, a2);
  if ( (v9 & 1) != 0 )
    return a3;
  else
    return a4;
}
