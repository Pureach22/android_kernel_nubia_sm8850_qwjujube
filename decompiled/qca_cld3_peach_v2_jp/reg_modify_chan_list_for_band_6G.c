_WORD *__fastcall reg_modify_chan_list_for_band_6G(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _WORD *result; // x0
  _WORD *v21; // x20
  unsigned int v22; // w21
  unsigned int chan_enum_for_freq; // w22
  __int64 v24; // x8
  _DWORD *v25; // x9
  int v26; // w10
  int v27; // w11
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int *v36; // x10
  unsigned __int64 i; // x11
  int v38; // w12

  if ( !*(_QWORD *)(a1 + 56728) )
    return (_WORD *)qdf_trace_msg(
                      0x51u,
                      8u,
                      "%s: pdev is NULL",
                      a3,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10,
                      "reg_modify_chan_list_for_band_6G");
  if ( (reg_get_keep_6ghz_sta_cli_connection(*(_QWORD *)(a1 + 56728)) & 1) != 0 )
  {
    result = (_WORD *)_qdf_mem_malloc(4u, "reg_modify_inactive_6g_channels", 881);
    if ( result )
    {
      v21 = result;
      qdf_mem_set(result, 4u, 0);
      reg_get_active_6ghz_freq_range_with_fcc_set(a1, v21);
      if ( *v21 && v21[1] )
      {
        v22 = ((__int64 (*)(void))reg_get_chan_enum_for_freq)();
        chan_enum_for_freq = reg_get_chan_enum_for_freq((unsigned __int16)v21[1]);
      }
      else
      {
        v22 = 102;
        chan_enum_for_freq = 102;
      }
      _qdf_mem_free((__int64)v21);
      result = (_WORD *)qdf_trace_msg(
                          0x51u,
                          8u,
                          "%s: disabling 6G",
                          v28,
                          v29,
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          v35,
                          "reg_modify_inactive_6g_channels");
      v36 = (int *)(a2 + 1524);
      for ( i = 42; i != 102; ++i )
      {
        if ( v22 > 0x65 || i > chan_enum_for_freq || chan_enum_for_freq > 0x65 || i < v22 )
        {
          v38 = *v36 | 1;
          *(v36 - 1) = 0;
          *v36 = v38;
        }
        v36 += 9;
      }
    }
  }
  else
  {
    result = (_WORD *)qdf_trace_msg(
                        0x51u,
                        8u,
                        "%s: disabling 6G",
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        "reg_modify_chan_list_for_band_6G");
    v24 = 0;
    do
    {
      v25 = (_DWORD *)(a2 + v24);
      v24 += 72;
      v26 = v25[381];
      v27 = v25[390];
      v25[380] = 0;
      v25[389] = 0;
      v25[381] = v26 | 1;
      v25[390] = v27 | 1;
    }
    while ( v24 != 2160 );
  }
  return result;
}
