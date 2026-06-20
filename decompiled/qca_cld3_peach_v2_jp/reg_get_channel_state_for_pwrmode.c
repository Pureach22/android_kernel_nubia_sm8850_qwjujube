__int64 __fastcall reg_get_channel_state_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int16 v11; // w9
  __int16 v12; // w10
  unsigned int v13; // w19
  unsigned int v14; // w12
  __int64 v15; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v11 = 0;
  v12 = 101;
  while ( 1 )
  {
    v13 = (v11 + v12) / 2;
    v14 = *(_DWORD *)(channel_map + 12LL * (int)v13);
    if ( v14 == a2 )
      break;
    if ( v14 >= a2 )
      v12 = v13 - 1;
    else
      v11 = v13 + 1;
    if ( v11 > v12 )
    {
      v15 = jiffies;
      if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: invalid channel center frequency %d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "reg_get_chan_enum_for_freq");
        reg_get_chan_enum_for_freq___last_ticks = v15;
      }
      return 4;
    }
  }
  if ( v13 <= 0x65 )
  {
    if ( reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11) )
      return reg_get_chan_state(a1, v13, a3, 1);
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg obj is NULL",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "reg_get_channel_state_for_pwrmode");
  }
  return 4;
}
