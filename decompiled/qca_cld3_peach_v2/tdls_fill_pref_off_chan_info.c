__int64 __fastcall tdls_fill_pref_off_chan_info(
        __int64 a1,
        _DWORD *a2,
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
  __int64 v13; // x22
  unsigned int v14; // w21
  unsigned int v15; // w23
  int v16; // w23
  unsigned int max_bw; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  __int64 v27; // x4

  v13 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
  if ( v13 )
  {
    v15 = a2[40];
    v14 = a2[41];
    if ( v14 && (tdls_is_6g_freq_allowed(*(_QWORD *)(*(_QWORD *)a1 + 216LL), v14) & 1) != 0 )
      qdf_trace_msg(
        0,
        8u,
        "%s: 6 GHz freq: %d supported for TDLS",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "tdls_get_offchan_freq",
        v14);
    else
      v14 = wlan_reg_legacy_chan_to_freq(v13, v15, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: pdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "tdls_get_offchan_freq");
    v14 = 0;
  }
  *(_DWORD *)(a3 + 492) = v14;
  v16 = a2[42];
  max_bw = wlan_mlme_get_max_bw();
  if ( wlan_reg_is_5ghz_ch_freq(v14) || max_bw <= 2 )
  {
    v26 = a2[42];
    if ( (v26 & 8) != 0 )
      LOBYTE(v16) = v26 & 0xF7;
  }
  v27 = *(unsigned int *)(a3 + 492);
  *(_BYTE *)(a3 + 496) = v16;
  return qdf_trace_msg(
           0,
           8u,
           "%s: Pref off channel freq %d chan width %d",
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           "tdls_fill_pref_off_chan_info",
           v27,
           (unsigned __int8)v16);
}
