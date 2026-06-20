__int64 __fastcall policy_mgr_nan_sap_pre_enable_conc_check(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD *v14; // x19
  char is_sap_mode; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int channel; // w21
  unsigned int _5ghz_social_ch_freq; // w22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  const char *v35; // x2
  const char *v36; // x2

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v35 = "%s: Invalid Context";
LABEL_26:
    qdf_trace_msg(0x4Fu, 2u, v35, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_nan_sap_pre_enable_conc_check");
    return 0;
  }
  v14 = (_QWORD *)context;
  is_sap_mode = policy_mgr_is_sap_mode(a2);
  if ( a2 == 5 || (is_sap_mode & 1) == 0 )
  {
    v36 = "%s: Not NAN or SAP mode";
LABEL_24:
    qdf_trace_msg(0x4Fu, 8u, v36, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_nan_sap_pre_enable_conc_check");
    return 1;
  }
  if ( !a3 )
  {
    v35 = "%s: Invalid channel";
    goto LABEL_26;
  }
  if ( (wlan_nan_get_sap_conc_support(*v14) & 1) == 0 )
  {
    v34 = "%s: NAN+SAP not supported in fw";
LABEL_28:
    qdf_trace_msg(0x4Fu, 8u, v34, v16, v17, v18, v19, v20, v21, v22, v23, "policy_mgr_nan_sap_pre_enable_conc_check");
    ucfg_nan_disable_concurrency(*v14);
    return 1;
  }
  if ( (policy_mgr_is_sap_mode(a2) & 1) != 0 )
  {
    channel = policy_mgr_mode_specific_get_channel(*v14, 5);
    _5ghz_social_ch_freq = wlan_nan_get_5ghz_social_ch_freq(v14[1]);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: SAP CH: %d NAN Ch: %d %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "policy_mgr_nan_sap_pre_enable_conc_check",
      a3,
      channel,
      _5ghz_social_ch_freq);
    if ( (ucfg_is_nan_conc_control_supported(*v14) & 1) != 0
      && (ucfg_is_nan_dbs_supported(*v14) & 1) == 0
      && (wlan_reg_is_same_band_freqs(channel, a3) & 1) == 0 )
    {
      if ( (policy_mgr_is_force_scc(*v14) & 1) != 0 )
        return 1;
      v34 = "%s: NAN and SAP are in different bands but SAP force SCC disabled";
      goto LABEL_28;
    }
    if ( (wlan_reg_is_same_band_freqs(channel, a3) & 1) == 0
      && (wlan_reg_is_same_band_freqs(_5ghz_social_ch_freq, a3) & 1) == 0 )
    {
      return 1;
    }
    if ( channel != a3 && _5ghz_social_ch_freq != a3 )
    {
      if ( (policy_mgr_is_force_scc(*v14) & 1) != 0 )
      {
        if ( (!wlan_reg_is_5ghz_ch_freq(a3)
           || (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*v14, _5ghz_social_ch_freq) & 1) != 0
           || *((_BYTE *)v14 + 2215))
          && (!wlan_reg_is_24ghz_ch_freq(a3)
           || (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*v14, channel) & 1) != 0
           || *((_BYTE *)v14 + 2215)) )
        {
          return 1;
        }
        v34 = "%s: NAN+SAP unsafe ch SCC disabled";
      }
      else
      {
        v34 = "%s: SAP force SCC disabled";
      }
      goto LABEL_28;
    }
    v36 = "%s: NAN+SAP SCC";
    goto LABEL_24;
  }
  return 1;
}
