__int64 __fastcall policy_mgr_2_freq_always_on_same_mac(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w19
  unsigned int v4; // w20
  int v6; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w22
  __int64 v16; // x24

  v3 = a3;
  v4 = a2;
  v6 = policy_mgr_2_freq_same_mac_in_dbs(a1, a2, a3);
  if ( (v6 & 1) != 0 )
    v15 = policy_mgr_2_freq_same_mac_in_sbs(a1, v4, v3);
  else
    v15 = 1;
  v16 = jiffies;
  if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_2_freq_always_on_same_mac",
      v4,
      v3,
      v6 & 1,
      v15 & 1);
    policy_mgr_2_freq_always_on_same_mac___last_ticks = v16;
  }
  return v6 & v15 & 1;
}
