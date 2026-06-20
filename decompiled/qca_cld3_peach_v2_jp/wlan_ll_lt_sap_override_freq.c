__int64 __fastcall wlan_ll_lt_sap_override_freq(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int valid_freq; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  if ( policy_mgr_is_vdev_ll_lt_sap(a1, a2)
    && (wlan_reg_is_24ghz_ch_freq(a3) || (unsigned int)policy_mgr_get_connection_count_with_ch_freq(a3)) )
  {
    valid_freq = ll_lt_sap_get_valid_freq(a1, a2, 0, 0);
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: Vdev %d ll_lt_sap old freq %d new freq %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_ll_lt_sap_override_freq",
      a2,
      a3,
      valid_freq);
    return valid_freq;
  }
  return a3;
}
