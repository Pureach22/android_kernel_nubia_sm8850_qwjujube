__int64 __fastcall policy_mgr_init_5g_low_high_cut_freq(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w4
  unsigned int v31; // w8
  unsigned int v32; // w20

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "policy_mgr_init_5g_low_high_cut_freq");
  v11 = context;
  v12 = policy_mgr_get_context(a1);
  if ( v12 )
  {
    v21 = (_DWORD *)v12;
    if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 )
    {
      v30 = v21[300];
      if ( v30 )
        goto LABEL_12;
      v31 = v21[323];
      if ( v31 <= v21[319] )
        v31 = v21[319];
      v32 = v31 - 1;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: sbs cutoff freq %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "policy_mgr_get_sbs_cut_off_freq",
        v31 - 1);
      v30 = v32;
      if ( v32 )
        goto LABEL_12;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "policy_mgr_get_sbs_cut_off_freq");
  }
  v30 = wlan_reg_max_5ghz_chan_freq();
LABEL_12:
  *(_DWORD *)(v11 + 1664) = v30;
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: 5g low high cutoff freq %d",
           v22,
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           v29,
           "policy_mgr_init_5g_low_high_cut_freq");
}
