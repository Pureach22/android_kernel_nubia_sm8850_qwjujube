__int64 __fastcall reg_get_chan_enum_for_freq(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int16 v10; // w9
  __int16 v11; // w10
  __int64 result; // x0
  unsigned int v13; // w12
  __int64 v14; // x20

  v10 = 0;
  v11 = 101;
  while ( 1 )
  {
    result = (unsigned int)((v11 + v10) / 2);
    v13 = *(_DWORD *)(channel_map + 12LL * (int)result);
    if ( v13 == a1 )
      break;
    if ( v13 >= a1 )
      v11 = result - 1;
    else
      v10 = result + 1;
    if ( v10 > v11 )
    {
      v14 = jiffies;
      if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: invalid channel center frequency %d",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "reg_get_chan_enum_for_freq");
        reg_get_chan_enum_for_freq___last_ticks = v14;
      }
      return 102;
    }
  }
  return result;
}
