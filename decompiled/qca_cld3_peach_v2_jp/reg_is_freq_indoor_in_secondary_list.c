__int64 __fastcall reg_is_freq_indoor_in_secondary_list(
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
  __int64 pdev_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int16 v20; // w9
  __int16 v21; // w10
  __int64 v22; // x4
  unsigned int v23; // w12
  __int64 v24; // x21
  __int64 v26; // x20

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_obj )
  {
    v20 = 0;
    v21 = 101;
    while ( 1 )
    {
      v22 = (unsigned int)((v20 + v21) / 2);
      v23 = *(_DWORD *)(channel_map + 12LL * (int)v22);
      if ( v23 == a2 )
        break;
      if ( v23 >= a2 )
        v21 = v22 - 1;
      else
        v20 = v22 + 1;
      if ( v20 > v21 )
      {
        v24 = jiffies;
        if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "reg_get_chan_enum_for_freq",
            a2);
          reg_get_chan_enum_for_freq___last_ticks = v24;
        }
        v22 = 102;
        goto LABEL_13;
      }
    }
    if ( (unsigned int)v22 < 0x66 )
      return (*(unsigned __int8 *)(pdev_obj + 36LL * (unsigned int)v22 + 3685) >> 1) & 1;
LABEL_13:
    v26 = jiffies;
    if ( reg_is_freq_indoor_in_secondary_list___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Invalid chan enum %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "reg_is_freq_indoor_in_secondary_list",
        v22);
      reg_is_freq_indoor_in_secondary_list___last_ticks = v26;
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "reg_is_freq_indoor_in_secondary_list");
    return 0;
  }
}
