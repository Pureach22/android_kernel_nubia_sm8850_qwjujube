__int64 __fastcall policy_mgr_are_sbs_chan(__int64 a1, unsigned int a2, unsigned int a3)
{
  char v6; // w8

  if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0 || wlan_reg_is_24ghz_ch_freq(a2) || wlan_reg_is_24ghz_ch_freq(a3) )
    v6 = 0;
  else
    v6 = policy_mgr_2_freq_same_mac_in_sbs(a1, a2, a3) ^ 1;
  return v6 & 1;
}
