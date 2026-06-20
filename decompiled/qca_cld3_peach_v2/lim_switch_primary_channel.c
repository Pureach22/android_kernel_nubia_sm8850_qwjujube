__int64 __fastcall lim_switch_primary_channel(
        __int64 a1,
        unsigned int a2,
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
  __int64 v14; // x22
  __int16 v15; // w8
  bool is_6ghz_chan_freq; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8

  v14 = a3 + 4096;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: freq: %d --> freq: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_switch_primary_channel",
    *(unsigned int *)(a3 + 284),
    a2);
  v15 = *(_WORD *)(a3 + 7216);
  *(_DWORD *)(a3 + 288) = a2;
  *(_DWORD *)(a3 + 284) = a2;
  *(_BYTE *)(v14 + 3078) = 0;
  *(_BYTE *)(v14 + 3090) = 0;
  *(_DWORD *)(a3 + 7176) = 0;
  *(_DWORD *)(a3 + 164) = 0;
  *(_WORD *)(a3 + 160) = 0;
  *(_WORD *)(a3 + 7184) = v15;
  is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(a2);
  v25 = 2;
  if ( !is_6ghz_chan_freq )
  {
    if ( wlan_reg_is_5ghz_ch_freq(a2) )
    {
      v25 = 1;
    }
    else if ( wlan_reg_is_24ghz_ch_freq(a2) )
    {
      v25 = 0;
    }
    else
    {
      v25 = 3;
    }
  }
  *(_DWORD *)(a3 + 168) = v25;
  *(_WORD *)(a3 + 152) = 2;
  *(_QWORD *)(a1 + 4040) = lim_switch_channel_cback;
  *(_QWORD *)(a1 + 4048) = 0;
  return lim_send_switch_chnl_params(a1, a3, v17, v18, v19, v20, v21, v22, v23, v24);
}
