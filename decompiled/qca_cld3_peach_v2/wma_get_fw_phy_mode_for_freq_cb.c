__int64 __fastcall wma_get_fw_phy_mode_for_freq_cb(
        unsigned int a1,
        unsigned int a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w22
  bool is_5ghz_ch_freq; // w0
  int v26; // w8
  unsigned int v27; // w2
  int v28; // w0
  __int64 result; // x0

  context = _cds_get_context(53, (__int64)"wma_get_fw_phy_mode_for_freq_cb", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    v23 = *(_DWORD *)(context[1] + 5964LL);
    if ( wlan_reg_is_24ghz_ch_freq(a1) && v23 == 2 )
      v23 = 4;
    is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a1);
    if ( (unsigned int)(v23 - 3) < 2 || v23 == 6 )
      v26 = 2;
    else
      v26 = v23;
    if ( is_5ghz_ch_freq )
      v27 = v26;
    else
      v27 = v23;
    v28 = (unsigned int)wma_chan_phy_mode(a1, a2, v27);
    result = wmi_host_to_fw_phymode(v28);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: MAC context is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_get_fw_phy_mode_for_freq_cb");
    result = 0;
  }
  *a3 = result;
  return result;
}
