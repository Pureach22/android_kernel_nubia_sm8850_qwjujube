__int64 __fastcall reg_get_min_max_bw_on_cur_chan_list(
        __int64 a1,
        unsigned int a2,
        _WORD *a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 pdev_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  pdev_obj = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( pdev_obj )
  {
    if ( a2 <= 0x65 )
    {
      if ( a3 )
        *a3 = *(_WORD *)(pdev_obj + 36LL * a2 + 20);
      if ( a4 )
        *a4 = *(_WORD *)(pdev_obj + 36LL * a2 + 22);
      return 0;
    }
    else
    {
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "reg_get_min_max_bw_on_cur_chan_list");
    return 16;
  }
}
