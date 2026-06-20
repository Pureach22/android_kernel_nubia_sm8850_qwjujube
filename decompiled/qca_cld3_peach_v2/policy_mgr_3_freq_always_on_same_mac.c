__int64 __fastcall policy_mgr_3_freq_always_on_same_mac(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 context; // x0
  __int64 v9; // x23
  char v10; // w22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char v19; // w23
  __int64 v20; // x25
  char v21; // w8
  __int64 v23; // x8

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v21 = 0;
    return v21 & 1;
  }
  v9 = context;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
    v21 = 1;
    return v21 & 1;
  }
  v10 = policy_mgr_3_freq_same_mac_in_freq_range(v9 + 1236, a2, a3, a4);
  if ( (v10 & 1) == 0 || (policy_mgr_is_hw_sbs_capable(*(_QWORD *)v9) & 1) == 0 )
    goto LABEL_7;
  if ( !*(_DWORD *)(v9 + 1200) )
  {
    v23 = 1268;
LABEL_16:
    v19 = policy_mgr_3_freq_same_mac_in_freq_range(v9 + v23, a2, a3, a4);
    goto LABEL_8;
  }
  if ( (policy_mgr_3_freq_same_mac_in_freq_range(v9 + 1332, a2, a3, a4) & 1) == 0 )
  {
    v23 = 1300;
    goto LABEL_16;
  }
LABEL_7:
  v19 = 1;
LABEL_8:
  v20 = jiffies;
  if ( policy_mgr_3_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: freq1 %d freq2 %d freq3 %d: Same mac:: DBS:%d SBS:%d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_3_freq_always_on_same_mac",
      a2,
      a3,
      a4,
      v10 & 1,
      v19 & 1);
    policy_mgr_3_freq_always_on_same_mac___last_ticks = v20;
  }
  v21 = v10 & v19;
  return v21 & 1;
}
