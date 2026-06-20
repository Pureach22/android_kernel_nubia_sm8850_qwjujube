__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index_cli_cli(__int64 a1)
{
  bool is_24ghz_ch_freq; // w0
  unsigned int v2; // w8
  unsigned int v3; // w9
  bool v6; // zf
  unsigned int v7; // w8

  if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C) )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
    if ( dword_8D4EF8 )
      v2 = 96;
    else
      v2 = 95;
    if ( dword_8D4EF8 )
      v3 = 92;
    else
      v3 = 91;
    if ( is_24ghz_ch_freq )
      return v3;
    else
      return v2;
  }
  else
  {
    if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
    {
      if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
        && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
      {
        v6 = dword_8D4EF8 == 0;
        v7 = 93;
      }
      else if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
             || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
      {
        v6 = dword_8D4EF8 == 0;
        v7 = 99;
      }
      else
      {
        v6 = dword_8D4EF8 == 0;
        v7 = 97;
      }
    }
    else
    {
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
        return 164;
      if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
        && !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
      {
        return 103;
      }
      v6 = dword_8D4EF8 == 0;
      v7 = 101;
    }
    if ( v6 )
      return v7;
    else
      return v7 + 1;
  }
}
