__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index_sta_sta(__int64 a1)
{
  bool is_24ghz_ch_freq; // w0
  bool v3; // zf
  unsigned int v4; // w8

  if ( (policy_mgr_is_ml_vdev_id(a1, (unsigned int)qword_8D4F00) & 1) != 0
    && (policy_mgr_is_ml_vdev_id(a1, (unsigned int)qword_8D4F24) & 1) != 0
    && (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) == 0 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
      goto LABEL_22;
    return 135;
  }
  if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C) )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
    v3 = dword_8D4EF8 == 0;
    if ( is_24ghz_ch_freq )
      v4 = 123;
    else
      v4 = 127;
    goto LABEL_23;
  }
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
    {
      v3 = dword_8D4EF8 == 0;
      v4 = 125;
    }
    else if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
           || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
    {
      v3 = dword_8D4EF8 == 0;
      v4 = 131;
    }
    else
    {
      v3 = dword_8D4EF8 == 0;
      v4 = 129;
    }
    goto LABEL_23;
  }
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
    return 164;
  if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
    return 135;
LABEL_22:
  v3 = dword_8D4EF8 == 0;
  v4 = 133;
LABEL_23:
  if ( v3 )
    return v4;
  else
    return v4 + 1;
}
