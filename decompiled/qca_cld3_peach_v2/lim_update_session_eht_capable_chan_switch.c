__int64 __fastcall lim_update_session_eht_capable_chan_switch(__int64 a1, __int64 a2, unsigned int a3)
{
  int v4; // w0
  char *v5; // x22
  char v8; // w9
  char v9; // w8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  v4 = *(_DWORD *)(a2 + 284);
  v5 = (char *)(a2 + 7170);
  *(_BYTE *)(a2 + 10071) = 1;
  *(_BYTE *)(a2 + 8676) = 1;
  if ( wlan_reg_is_6ghz_chan_freq(v4) && !wlan_reg_is_6ghz_chan_freq(a3) )
  {
    v9 = 0;
    v8 = 1;
    goto LABEL_7;
  }
  if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284)) && wlan_reg_is_6ghz_chan_freq(a3) )
  {
    v8 = 0;
    v9 = 1;
LABEL_7:
    *(_BYTE *)(a2 + 155) = v8;
    *v5 = v8;
    v5[1594] = v9;
  }
  if ( wlan_reg_is_24ghz_ch_freq(a3) && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2875LL) & 1) == 0 )
  {
    *v5 = 0;
  }
  else if ( wlan_reg_is_5ghz_ch_freq(a3) )
  {
    *v5 = 1;
  }
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: eht_capable:%d he_capable:%d  ht:%d vht:%d 6ghz_band:%d new freq:%d vht in 2.4gh:%d",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           "lim_update_session_eht_capable_chan_switch",
           (unsigned __int8)v5[2901],
           (unsigned __int8)v5[1506],
           *(unsigned __int8 *)(a2 + 155),
           (unsigned __int8)v5[1594],
           a3,
           *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2875LL));
}
