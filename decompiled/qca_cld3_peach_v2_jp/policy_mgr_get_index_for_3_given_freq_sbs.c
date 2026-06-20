__int64 __fastcall policy_mgr_get_index_for_3_given_freq_sbs(
        __int64 *a1,
        int *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int sbs_cut_off_freq; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w24
  __int64 result; // x0
  int v29; // w8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  if ( (policy_mgr_are_sbs_chan(*a1, a3, a4) & 1) == 0
    && (policy_mgr_are_sbs_chan(*a1, a4, a5) & 1) == 0
    && (policy_mgr_are_sbs_chan(*a1, a5, a3) & 1) == 0 )
  {
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: freq1 %d, freq2 %d and freq3 %d, none of the 2 connections/3 vdevs are leading to SBS",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "policy_mgr_get_index_for_3_given_freq_sbs",
             a3,
             a4,
             a5);
  }
  sbs_cut_off_freq = policy_mgr_get_sbs_cut_off_freq(*a1);
  if ( !sbs_cut_off_freq )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid cutoff freq",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "policy_mgr_get_index_for_3_given_freq_sbs");
  v27 = sbs_cut_off_freq;
  if ( policy_mgr_can_2ghz_share_low_high_5ghz_sbs((__int64)a1) )
  {
    result = wlan_reg_is_24ghz_ch_freq(a3);
    if ( (result & 1) != 0
      || (result = wlan_reg_is_24ghz_ch_freq(a4), (result & 1) != 0)
      || (result = wlan_reg_is_24ghz_ch_freq(a5), (result & 1) != 0) )
    {
      v29 = 32;
LABEL_31:
      *a2 = v29;
      return result;
    }
  }
  if ( (policy_mgr_2_freq_same_mac_in_sbs(*a1, a3, a4) & 1) != 0 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(a3) )
      a5 = a4;
    else
      a5 = a3;
    if ( !a5 )
      return qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: shared_5_ghz_freq %d is not 5 / 6 GHZ",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "policy_mgr_get_index_for_3_given_freq_sbs",
               a5);
  }
  else if ( (policy_mgr_2_freq_same_mac_in_sbs(*a1, a4, a5) & 1) != 0 )
  {
    if ( !wlan_reg_is_24ghz_ch_freq(a4) )
      a5 = a4;
    if ( !a5 )
      return qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: shared_5_ghz_freq %d is not 5 / 6 GHZ",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "policy_mgr_get_index_for_3_given_freq_sbs",
               a5);
  }
  else
  {
    if ( (policy_mgr_2_freq_same_mac_in_sbs(*a1, a5, a3) & 1) == 0 )
    {
      a5 = 0;
      return qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: shared_5_ghz_freq %d is not 5 / 6 GHZ",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "policy_mgr_get_index_for_3_given_freq_sbs",
               a5);
    }
    if ( !wlan_reg_is_24ghz_ch_freq(a3) )
      a5 = a3;
    if ( !a5 )
      return qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: shared_5_ghz_freq %d is not 5 / 6 GHZ",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "policy_mgr_get_index_for_3_given_freq_sbs",
               a5);
  }
  result = wlan_reg_is_24ghz_ch_freq(a5);
  if ( (result & 1) == 0 )
  {
    if ( a5 >= v27 )
      v29 = 30;
    else
      v29 = 31;
    goto LABEL_31;
  }
  return qdf_trace_msg(
           0x4Fu,
           2u,
           "%s: shared_5_ghz_freq %d is not 5 / 6 GHZ",
           v30,
           v31,
           v32,
           v33,
           v34,
           v35,
           v36,
           v37,
           "policy_mgr_get_index_for_3_given_freq_sbs",
           a5);
}
