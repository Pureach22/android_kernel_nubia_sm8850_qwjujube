__int64 __fastcall tdls_check_6g_freq_allowed(__int64 a1, unsigned int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned __int8 chan_enum_for_freq; // w21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !wlan_reg_is_6ghz_chan_freq(a2) )
    return 1;
  if ( a1 )
  {
    if ( wlan_reg_is_6ghz_chan_freq(a2) && (wlan_cfg80211_tdls_is_fw_6ghz_capable(a1) & 1) != 0 )
    {
      chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(a2, v4, v5, v6, v7, v8, v9, v10, v11);
      if ( (wlan_reg_is_6ghz_psc_chan_freq(a2, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0
        && (wlan_reg_is_freq_idx_enabled(a1, chan_enum_for_freq, 6u, v4, v5, v6, v7, v8, v9, v10, v11) & 1) != 0 )
      {
        return 1;
      }
    }
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: 6GHz freq:%d not allowed for TDLS",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "tdls_check_6g_freq_allowed",
    a2);
  return 0;
}
