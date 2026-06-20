__int64 __fastcall hdd_check_and_fill_freq(
        unsigned int a1,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // w5
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  bool is_24ghz_ch_freq; // w0
  bool is_5ghz_ch_freq; // w0
  bool is_6ghz_chan_freq; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char is_freq_enabled; // w8
  __int64 result; // x0

  if ( a1 > 0xAD )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a1);
    v14 = a1;
    if ( !is_24ghz_ch_freq )
    {
      is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a1);
      v14 = a1;
      if ( !is_5ghz_ch_freq )
      {
        is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(a1);
        v14 = a1;
        if ( !is_6ghz_chan_freq )
          return 0;
      }
    }
  }
  else
  {
    v14 = wlan_reg_legacy_chan_to_freq(a3, a1, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  *a2 = v14;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: channel num: %d, freq: %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_check_and_fill_freq",
    a1);
  if ( !*a2 )
    return 1;
  is_freq_enabled = wlan_reg_is_freq_enabled(a3, *a2, v26, v27, v28, v29, v30, v31, v32, v33);
  result = 0;
  if ( (is_freq_enabled & 1) != 0 )
    return 1;
  return result;
}
