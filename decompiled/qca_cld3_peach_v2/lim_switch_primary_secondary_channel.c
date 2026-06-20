__int64 __fastcall lim_switch_primary_secondary_channel(__int64 a1, __int64 a2)
{
  unsigned int v2; // w22
  _BYTE *v3; // x23
  char v5; // w24
  char v6; // w25
  int v7; // w21
  bool is_6ghz_chan_freq; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w8
  int v19; // w8
  __int16 v20; // w8

  v2 = *(_DWORD *)(a2 + 7204);
  v3 = (_BYTE *)(a2 + 4096);
  v5 = *(_BYTE *)(a2 + 7209);
  v6 = *(_BYTE *)(a2 + 7210);
  v7 = *(_DWORD *)(a2 + 7212);
  *(_DWORD *)(a2 + 288) = v2;
  is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(v2);
  v18 = 2;
  if ( !is_6ghz_chan_freq )
  {
    if ( wlan_reg_is_5ghz_ch_freq(v2) )
    {
      v18 = 1;
    }
    else if ( wlan_reg_is_24ghz_ch_freq(v2) )
    {
      v18 = 0;
    }
    else
    {
      v18 = 3;
    }
  }
  *(_DWORD *)(a2 + 168) = v18;
  *(_WORD *)(a2 + 152) = 2;
  *(_QWORD *)(a1 + 4040) = lim_switch_channel_cback;
  *(_QWORD *)(a1 + 4048) = 0;
  if ( *(_DWORD *)(a2 + 284) != v2 || *(_DWORD *)(a2 + 7176) != v7 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: freq: %d[%d] --> freq: %d[%d]",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "lim_switch_primary_secondary_channel");
    *(_DWORD *)(a2 + 284) = v2;
  }
  if ( *(_DWORD *)(a2 + 164) != (unsigned __int8)v3[3115] )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: HT sec chnl: %d --> HT sec chnl: %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "lim_switch_primary_secondary_channel");
    v19 = (unsigned __int8)v3[3115];
    *(_DWORD *)(a2 + 164) = v19;
    LOBYTE(v19) = v19 != 0;
    *(_BYTE *)(a2 + 160) = v19;
    *(_BYTE *)(a2 + 161) = v19;
  }
  v20 = *(_WORD *)(a2 + 7216);
  v3[3078] = v5;
  v3[3090] = v6;
  *(_DWORD *)(a2 + 7176) = v7;
  *(_WORD *)(a2 + 7184) = v20;
  return lim_send_switch_chnl_params(a1, a2, v10, v11, v12, v13, v14, v15, v16, v17);
}
