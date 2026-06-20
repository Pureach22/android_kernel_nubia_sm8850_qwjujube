__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index_sap_ll_lt_sap(__int64 a1)
{
  char *v2; // x8
  unsigned int v3; // w21
  unsigned int v4; // w19

  if ( (_DWORD)pm_conc_connection_list == 1 )
    v2 = (char *)&pm_conc_connection_list + 4;
  else
    v2 = (char *)&qword_8D4F0C + 4;
  v3 = *(_DWORD *)v2;
  if ( v3 < (unsigned int)policy_mgr_get_sbs_cut_off_freq(a1) )
    v4 = 154;
  else
    v4 = 155;
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
  {
    return 164;
  }
  else if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
         || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
  {
    return 153;
  }
  return v4;
}
