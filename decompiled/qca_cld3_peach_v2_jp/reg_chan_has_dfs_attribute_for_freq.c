__int64 __fastcall reg_chan_has_dfs_attribute_for_freq(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int chan_enum_for_freq; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  __int64 pdev_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  chan_enum_for_freq = reg_get_chan_enum_for_freq(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( chan_enum_for_freq <= 0x65 )
  {
    v20 = chan_enum_for_freq;
    pdev_obj = reg_get_pdev_obj(a1, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( pdev_obj )
      return (*(unsigned __int8 *)(pdev_obj + 36LL * v20 + 12) >> 3) & 1;
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg obj is NULL",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "reg_chan_has_dfs_attribute_for_freq");
  }
  return 0;
}
