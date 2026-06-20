__int64 __fastcall policy_mgr_allow_same_mac_same_freq(__int64 a1, unsigned int a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20

  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 && (policy_mgr_is_interband_mcc_supported(a1) & 1) != 0 )
  {
    v14 = jiffies;
    if ( policy_mgr_allow_same_mac_same_freq___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: allow 2 intf SCC + new intf ch %d for legacy hw",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "policy_mgr_allow_same_mac_same_freq",
        a2);
      policy_mgr_allow_same_mac_same_freq___last_ticks = v14;
      return 1;
    }
    return 1;
  }
  if ( (_DWORD)pm_conc_connection_list == 5 && (_DWORD)qword_8D4F0C == 4
    || (_DWORD)pm_conc_connection_list == 4 && (_DWORD)qword_8D4F0C == 5
    || (policy_mgr_2_freq_always_on_same_mac(a1, a2, HIDWORD(pm_conc_connection_list)) & 1) == 0
    || (policy_mgr_is_3rd_conn_on_same_band_allowed(a1, a3, a2) & 1) != 0 )
  {
    return 1;
  }
  v24 = jiffies;
  if ( policy_mgr_allow_same_mac_same_freq___last_ticks_192 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: don't allow 3rd home channel on same MAC for sta+multi-AP",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_allow_same_mac_same_freq");
    policy_mgr_allow_same_mac_same_freq___last_ticks_192 = v24;
  }
  return 0;
}
