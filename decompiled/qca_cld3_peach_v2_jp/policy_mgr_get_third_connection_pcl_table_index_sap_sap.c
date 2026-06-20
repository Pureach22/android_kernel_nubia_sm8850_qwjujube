__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index_sap_sap(__int64 a1)
{
  bool is_24ghz_ch_freq; // w0
  unsigned int v2; // w8
  unsigned int v3; // w9
  bool v6; // zf
  unsigned int v7; // w8

  if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_81C464) )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
    if ( dword_81C450 )
      v2 = 109;
    else
      v2 = 108;
    if ( dword_81C450 )
      v3 = 105;
    else
      v3 = 104;
    if ( is_24ghz_ch_freq )
      return v3;
    else
      return v2;
  }
  else
  {
    if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_81C464)) & 1) != 0 )
    {
      if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
        && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) )
      {
        v6 = dword_81C450 == 0;
        v7 = 106;
      }
      else if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
             || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) )
      {
        v6 = dword_81C450 == 0;
        v7 = 112;
      }
      else
      {
        v6 = dword_81C450 == 0;
        v7 = 110;
      }
    }
    else
    {
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_81C464)) & 1) != 0 )
        return 164;
      if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
        && !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) )
      {
        return 116;
      }
      v6 = dword_81C450 == 0;
      v7 = 114;
    }
    if ( v6 )
      return v7;
    else
      return v7 + 1;
  }
}
