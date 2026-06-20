__int64 __fastcall reg_get_channel_state_from_secondary_list_for_freq(
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
  __int16 v10; // w9
  __int16 v11; // w10
  unsigned int v12; // w19
  unsigned int v13; // w12
  __int64 v14; // x20
  __int64 pdev_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v10 = 0;
  v11 = 101;
  while ( 1 )
  {
    v12 = (v10 + v11) / 2;
    v13 = *(_DWORD *)(channel_map + 12LL * (int)v12);
    if ( v13 == a2 )
      break;
    if ( v13 >= a2 )
      v11 = v12 - 1;
    else
      v10 = v12 + 1;
    if ( v10 > v11 )
    {
      v14 = jiffies;
      if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: invalid channel center frequency %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "reg_get_chan_enum_for_freq");
        reg_get_chan_enum_for_freq___last_ticks = v14;
      }
      return 4;
    }
  }
  if ( v12 <= 0x65 )
  {
    pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( pdev_obj )
      return *(unsigned int *)(pdev_obj + 36LL * v12 + 3680);
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg obj is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "reg_get_channel_state_from_secondary_list_for_freq");
  }
  return 4;
}
