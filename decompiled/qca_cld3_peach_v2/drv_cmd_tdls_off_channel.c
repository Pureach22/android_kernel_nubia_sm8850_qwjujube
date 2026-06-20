__int64 __fastcall drv_cmd_tdls_off_channel(_QWORD *a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int channel_state_for_pwrmode; // w0
  __int64 v24; // x5
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  unsigned int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  if ( sscanf((const char *)(a3 + a4), "%d", &v34) == 1 )
  {
    v14 = wlan_reg_legacy_chan_to_freq(*(_QWORD *)(a2 + 8), v34, v6, v7, v8, v9, v10, v11, v12, v13);
    channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                  *(_QWORD *)(a2 + 8),
                                  v14,
                                  0,
                                  v15,
                                  v16,
                                  v17,
                                  v18,
                                  v19,
                                  v20,
                                  v21,
                                  v22);
    if ( channel_state_for_pwrmode > 4
      || (v24 = channel_state_for_pwrmode, ((1 << channel_state_for_pwrmode) & 0x15) == 0) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Tdls offchannel num: %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "drv_cmd_tdls_off_channel",
        v34,
        v24);
      result = hdd_set_tdls_offchannel(a2, *a1, v34);
      goto LABEL_6;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: reg state of the  channel %d is %d and not supported",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "drv_cmd_tdls_off_channel",
      v34,
      channel_state_for_pwrmode);
  }
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
