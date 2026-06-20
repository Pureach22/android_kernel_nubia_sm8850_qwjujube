__int64 __fastcall tdls_get_6g_pwr_for_power_type(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x22
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  unsigned __int8 band_channel_list_for_pwrmode; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w8
  __int64 v26; // x24
  unsigned int *v27; // x25
  unsigned int v28; // w19

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 || !wlan_reg_is_6ghz_chan_freq(a2) )
    return 0;
  result = _qdf_mem_malloc(0xE58u, "tdls_get_6g_pwr_for_power_type", 883);
  if ( result )
  {
    v15 = result;
    band_channel_list_for_pwrmode = wlan_reg_get_band_channel_list_for_pwrmode(
                                      v3,
                                      4,
                                      result,
                                      a3,
                                      0,
                                      v7,
                                      v8,
                                      v9,
                                      v10,
                                      v11,
                                      v12,
                                      v13,
                                      v14);
    v25 = 0;
    v26 = band_channel_list_for_pwrmode;
    if ( band_channel_list_for_pwrmode )
    {
      v27 = (unsigned int *)(v15 + 16);
      do
      {
        if ( *(v27 - 4) == a2 )
        {
          qdf_trace_msg(
            0,
            8u,
            "%s: power for power type %d channel %d is %d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "tdls_get_6g_pwr_for_power_type",
            a3,
            a2,
            *v27);
          v25 = *v27;
        }
        --v26;
        v27 += 9;
      }
      while ( v26 );
    }
    v28 = v25;
    _qdf_mem_free(v15);
    return v28;
  }
  return result;
}
