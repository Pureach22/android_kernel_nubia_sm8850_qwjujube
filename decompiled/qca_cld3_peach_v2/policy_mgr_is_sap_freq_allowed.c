__int64 __fastcall policy_mgr_is_sap_freq_allowed(__int64 a1, int a2, unsigned int a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  unsigned int channel; // w0
  __int64 v27; // x8
  unsigned int v28; // w22
  unsigned int _5ghz_social_ch_freq; // w21

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v15 = context;
    if ( (a2 != 3 || (wlan_mlme_get_coex_unsafe_chan_nb_user_prefer_for_p2p_go(a1) & 1) == 0)
      && (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, a3) & 1) == 0 )
    {
      if ( (policy_mgr_sta_sap_scc_on_lte_coex_chan(a1) & 1) != 0 && (policy_mgr_is_sta_sap_scc(a1, a3, 0) & 1) != 0 )
      {
        v24 = "%s: unsafe freq %d for sap is allowed";
      }
      else
      {
        if ( (wlan_nan_is_disc_active(a1) & 1) == 0 )
          return 0;
        channel = policy_mgr_mode_specific_get_channel(a1, 5);
        v27 = *(_QWORD *)(v15 + 8);
        v28 = channel;
        _5ghz_social_ch_freq = wlan_nan_get_5ghz_social_ch_freq(v27);
        if ( (wlan_reg_is_same_band_freqs(v28, a3) & 1) == 0
          && (wlan_reg_is_same_band_freqs(_5ghz_social_ch_freq, a3) & 1) == 0 )
        {
          return 0;
        }
        if ( (policy_mgr_is_force_scc(a1) & 1) == 0 || (policy_mgr_get_nan_sap_scc_on_lte_coex_chnl(a1) & 1) == 0 )
          return 0;
        v24 = "%s: NAN+SAP SCC on unsafe freq %d is allowed";
      }
      qdf_trace_msg(0x4Fu, 8u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "policy_mgr_is_sap_freq_allowed", a3);
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: context is NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_is_sap_freq_allowed");
  }
  return 1;
}
