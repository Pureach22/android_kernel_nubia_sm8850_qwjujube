__int64 __fastcall reg_remove_puncture(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 pdev_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v21; // x20

  pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( pdev_obj )
  {
    v18 = 0;
    v19 = pdev_obj + 7374;
    do
    {
      if ( *(_BYTE *)(v19 + v18) )
        *(_BYTE *)(v19 + v18) = 0;
      v18 += 36;
    }
    while ( v18 != 3672 );
    reg_compute_pdev_current_chan_list(pdev_obj, v10, v11, v12, v13, v14, v15, v16, v17);
    return 0;
  }
  else
  {
    v21 = jiffies;
    if ( reg_remove_puncture___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: pdev reg obj is NULL",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "reg_remove_puncture");
      reg_remove_puncture___last_ticks = v21;
    }
    return 16;
  }
}
