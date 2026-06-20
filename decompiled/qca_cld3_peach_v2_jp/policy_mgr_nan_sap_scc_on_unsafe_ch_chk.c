__int64 __fastcall policy_mgr_nan_sap_scc_on_unsafe_ch_chk(__int64 a1, unsigned int a2)
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
  _QWORD *v13; // x19
  unsigned int channel; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  unsigned int _5ghz_social_ch_freq; // w23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v42; // x1

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v13 = (_QWORD *)context;
    channel = policy_mgr_mode_specific_get_channel(a1, 5);
    if ( channel )
    {
      v23 = channel;
      _5ghz_social_ch_freq = wlan_nan_get_5ghz_social_ch_freq(v13[1]);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Freq SAP: %d NAN: %d %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "policy_mgr_nan_sap_scc_on_unsafe_ch_chk",
        a2,
        v23,
        _5ghz_social_ch_freq);
      if ( (wlan_reg_is_same_band_freqs(v23, a2) & 1) != 0 )
      {
        if ( (policy_mgr_is_force_scc(*v13) & 1) != 0 )
        {
          if ( (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*v13, v23) & 1) != 0 )
            return 1;
LABEL_12:
          if ( *((_BYTE *)v13 + 2215) )
            return 1;
          goto LABEL_14;
        }
        goto LABEL_14;
      }
      if ( (wlan_reg_is_same_band_freqs(_5ghz_social_ch_freq, a2) & 1) != 0 )
      {
        if ( (policy_mgr_is_force_scc(*v13) & 1) != 0 )
        {
          if ( (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*v13, _5ghz_social_ch_freq) & 1) != 0 )
            return 1;
          goto LABEL_12;
        }
LABEL_14:
        qdf_trace_msg(
          0x4Fu,
          4u,
          "%s: NAN+SAP unsafe ch SCC not allowed. Disabling NAN",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "policy_mgr_nan_sap_scc_on_unsafe_ch_chk");
        v13[147] = a1;
        v13[146] = policy_mgr_nan_disable_work;
        v13[142] = 0xFFFFFFFE00000LL;
        v13[143] = v13 + 143;
        v13[144] = v13 + 143;
        v42 = system_wq;
        v13[145] = _qdf_defer_func;
        queue_work_on(32, v42, v13 + 142);
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: No NAN+SAP SCC",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_nan_sap_scc_on_unsafe_ch_chk");
    }
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
      "policy_mgr_nan_sap_scc_on_unsafe_ch_chk");
  }
  return 0;
}
