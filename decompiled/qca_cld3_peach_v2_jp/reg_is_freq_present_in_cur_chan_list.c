__int64 __fastcall reg_is_freq_present_in_cur_chan_list(
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
  __int64 i; // x8
  __int64 v22; // x21
  __int64 v23; // x20

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_obj )
  {
    for ( i = 0; i != 3672; i += 36 )
    {
      if ( *(_DWORD *)(pdev_obj + i) == a2 && *(_DWORD *)(pdev_obj + i + 8) && (*(_BYTE *)(pdev_obj + i + 12) & 1) == 0 )
        return 1;
    }
    v22 = jiffies;
    if ( reg_is_freq_present_in_cur_chan_list___last_ticks_42 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Channel center frequency %d not found",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "reg_is_freq_present_in_cur_chan_list",
        a2);
      reg_is_freq_present_in_cur_chan_list___last_ticks_42 = v22;
      return 0;
    }
    return 0;
  }
  v23 = jiffies;
  if ( reg_is_freq_present_in_cur_chan_list___last_ticks - jiffies + 125 >= 0 )
    return 0;
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: pdev reg obj is NULL",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "reg_is_freq_present_in_cur_chan_list");
  reg_is_freq_present_in_cur_chan_list___last_ticks = v23;
  return 0;
}
