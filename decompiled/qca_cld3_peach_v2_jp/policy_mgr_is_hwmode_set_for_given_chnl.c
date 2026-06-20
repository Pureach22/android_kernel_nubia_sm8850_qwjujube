__int64 __fastcall policy_mgr_is_hwmode_set_for_given_chnl(__int64 a1, unsigned int a2)
{
  bool is_24ghz_ch_freq; // w21
  char is_current_hwmode_dbs; // w20
  char is_hw_dbs_required_for_band; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0

  if ( (policy_mgr_is_hwmode_offload_enabled() & 1) != 0 )
    return 1;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
    return 1;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a2);
  is_current_hwmode_dbs = policy_mgr_is_current_hwmode_dbs(a1);
  is_hw_dbs_required_for_band = policy_mgr_is_hw_dbs_required_for_band(a1, 1);
  if ( !is_24ghz_ch_freq || (is_hw_dbs_required_for_band & 1) == 0 )
    return 1;
  result = 1;
  if ( (is_current_hwmode_dbs & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: HW mode is not yet in DBS!!!!!",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_is_hwmode_set_for_given_chnl");
    return 0;
  }
  return result;
}
