__int64 __fastcall reg_legacy_chan_to_freq(
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
  __int64 v21; // x20

  if ( (_BYTE)a2 )
  {
    pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( pdev_obj )
    {
      return reg_compute_chan_to_freq_for_chlist(pdev_obj + 7344, a2, 0, 41);
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
        "reg_compute_chan_to_freq");
      return 0;
    }
  }
  else
  {
    v21 = jiffies;
    if ( reg_legacy_chan_to_freq___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 8u, "%s: Invalid channel %d", a3, a4, a5, a6, a7, a8, a9, a10, "reg_legacy_chan_to_freq", 0);
      reg_legacy_chan_to_freq___last_ticks = v21;
    }
    return 0;
  }
}
