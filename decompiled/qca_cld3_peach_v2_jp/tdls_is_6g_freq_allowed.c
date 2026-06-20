__int64 __fastcall tdls_is_6g_freq_allowed(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19
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
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( a1 )
  {
    v2 = a1;
    if ( wlan_reg_is_6ghz_chan_freq(a2)
      && (wlan_cfg80211_tdls_is_fw_6ghz_capable(v2) & 1) != 0
      && (chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(a2, v4, v5, v6, v7, v8, v9, v10, v11),
          (wlan_reg_is_6ghz_psc_chan_freq(a2, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0) )
    {
      LOBYTE(a1) = wlan_reg_is_freq_idx_enabled(v2, chan_enum_for_freq, 6u, v21, v22, v23, v24, v25, v26, v27, v28);
    }
    else
    {
      LOBYTE(a1) = 0;
    }
  }
  return a1 & 1;
}
