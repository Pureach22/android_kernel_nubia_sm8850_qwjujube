bool __fastcall policy_mgr_will_freq_lead_to_mcc(__int64 a1, unsigned int a2)
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
  unsigned __int64 v13; // x23
  bool v14; // w27
  _BYTE *v15; // x28
  bool v16; // cf
  unsigned int v17; // w24
  int v18; // w25
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w26
  __int64 v28; // x22
  __int64 v30; // [xsp+8h] [xbp-8h]

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v30 = context;
    qdf_mutex_acquire(context + 56);
    v13 = 0;
    v14 = 1;
    v15 = (char *)&qword_8D4F00 + 4;
    do
    {
      if ( *v15 == 1 )
      {
        v17 = *((_DWORD *)v15 - 6);
        v18 = policy_mgr_2_freq_same_mac_in_dbs(a1, a2, v17);
        if ( (v18 & 1) != 0 )
          v27 = policy_mgr_2_freq_same_mac_in_sbs(a1, a2, v17);
        else
          v27 = 1;
        v28 = jiffies;
        if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "policy_mgr_2_freq_always_on_same_mac",
            a2,
            v17,
            v18 & 1,
            v27 & 1);
          policy_mgr_2_freq_always_on_same_mac___last_ticks = v28;
        }
        if ( (v18 & v27 & 1) != 0 )
          break;
      }
      v16 = v13++ >= 4;
      v15 += 36;
      v14 = !v16;
    }
    while ( v13 != 5 );
    qdf_mutex_release(v30 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_will_freq_lead_to_mcc");
    return 0;
  }
  return v14;
}
