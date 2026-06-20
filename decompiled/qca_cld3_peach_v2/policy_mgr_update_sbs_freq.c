__int64 __fastcall policy_mgr_update_sbs_freq(__int64 a1, __int64 a2)
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
  __int64 v13; // x21

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v13 = context;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: sbs_lower_band_end_freq %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_update_sbs_freq",
      *(unsigned int *)(a2 + 5772));
    if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a2 + 5772)) || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 5772)) )
      *(_DWORD *)(v13 + 1200) = *(_DWORD *)(a2 + 5772);
    policy_mgr_update_hw_mode_list(a1, a2);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_update_sbs_freq");
    return 16;
  }
}
