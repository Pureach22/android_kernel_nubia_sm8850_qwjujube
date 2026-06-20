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
  bool is_6ghz_chan_freq; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8

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
  *(_DWORD *)(a3 + 288) = a2;
  *(_DWORD *)(a3 + 284) = a2;
  *(_BYTE *)(v14 + 3078) = 0;
  *(_BYTE *)(v14 + 3088) = 0;
  *(_DWORD *)(a3 + 7176) = 0;
  *(_DWORD *)(a3 + 164) = 0;
  *(_WORD *)(a3 + 160) = 0;
  is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(a2);
  v24 = 2;
  if ( !is_6ghz_chan_freq )
  {
    if ( wlan_reg_is_5ghz_ch_freq(a2) )
    {
      v24 = 1;
    }
    else if ( wlan_reg_is_24ghz_ch_freq(a2) )
    {
      v24 = 0;
    }
    else
    {
      v24 = 3;
    }
  }
  *(_DWORD *)(a3 + 168) = v24;
  *(_WORD *)(a3 + 152) = 2;
  *(_QWORD *)(a1 + 4040) = lim_switch_channel_cback;
  *(_QWORD *)(a1 + 4048) = 0;
  return lim_send_switch_chnl_params(a1, a3, v16, v17, v18, v19, v20, v21, v22, v23);
}
