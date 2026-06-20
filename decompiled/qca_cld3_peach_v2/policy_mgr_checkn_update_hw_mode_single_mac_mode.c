__int64 __fastcall policy_mgr_checkn_update_hw_mode_single_mac_mode(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 result; // x0
  char is_hw_dbs_required_for_band; // w22
  const char *v16; // x2
  unsigned int v17; // w1

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v13 = context;
    result = policy_mgr_is_hw_dbs_capable(a1);
    if ( (result & 1) == 0 )
      return result;
    if ( *(_DWORD *)(v13 + 268) == 21 )
      qdf_mc_timer_stop(v13 + 120);
    is_hw_dbs_required_for_band = policy_mgr_is_hw_dbs_required_for_band(a1, 1);
    if ( (is_hw_dbs_required_for_band & 1) != 0 && wlan_reg_is_24ghz_ch_freq(a2) )
    {
      v16 = "%s: DBS required for new connection";
    }
    else
    {
      qdf_mutex_acquire(v13 + 56);
      if ( (BYTE4(qword_8D4F00) != 1
         || ((wlan_reg_is_same_band_freqs(a2, HIDWORD(pm_conc_connection_list)) & 1) != 0
          || !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && !wlan_reg_is_24ghz_ch_freq(a2))
         && ((is_hw_dbs_required_for_band & 1) == 0 || !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))))
        && (BYTE4(qword_8D4F24) != 1
         || ((wlan_reg_is_same_band_freqs(a2, HIDWORD(qword_8D4F0C)) & 1) != 0
          || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) && !wlan_reg_is_24ghz_ch_freq(a2))
         && ((is_hw_dbs_required_for_band & 1) == 0 || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C))))
        && (BYTE4(qword_8D4F48) != 1
         || ((wlan_reg_is_same_band_freqs(a2, HIDWORD(qword_8D4F30)) & 1) != 0
          || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F30)) && !wlan_reg_is_24ghz_ch_freq(a2))
         && ((is_hw_dbs_required_for_band & 1) == 0 || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F30))))
        && (BYTE4(qword_8D4F6C) != 1
         || ((wlan_reg_is_same_band_freqs(a2, HIDWORD(qword_8D4F54)) & 1) != 0
          || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F54)) && !wlan_reg_is_24ghz_ch_freq(a2))
         && ((is_hw_dbs_required_for_band & 1) == 0 || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F54))))
        && (BYTE4(qword_8D4F90) != 1
         || ((wlan_reg_is_same_band_freqs(a2, HIDWORD(qword_8D4F78)) & 1) != 0
          || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F78)) && !wlan_reg_is_24ghz_ch_freq(a2))
         && ((is_hw_dbs_required_for_band & 1) == 0 || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F78)))) )
      {
        qdf_mutex_release(v13 + 56);
        return pm_dbs_opportunistic_timer_handler(a1);
      }
      qdf_mutex_release(v13 + 56);
      v16 = "%s: DBS required";
    }
    v17 = 8;
  }
  else
  {
    v16 = "%s: Invalid Context";
    v17 = 2;
  }
  return qdf_trace_msg(
           0x4Fu,
           v17,
           v16,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           "policy_mgr_checkn_update_hw_mode_single_mac_mode");
}
