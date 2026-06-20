__int64 __fastcall reg_get_superchan_entry(
        __int64 a1,
        unsigned int a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int16 v11; // w20
  __int64 pdev_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 v24; // x20

  if ( a2 - 42 >= 0x3C )
    v11 = 102;
  else
    v11 = a2 - 42;
  if ( v11 < 0x66u )
  {
    pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( pdev_obj )
    {
      if ( a3 )
      {
        if ( v11 < 0x3Cu )
        {
          *a3 = pdev_obj + 268LL * v11 + 36940;
          return 0;
        }
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: sup_idx is out of bounds",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "reg_get_superchan_entry");
      }
      else
      {
        v24 = jiffies;
        if ( reg_get_superchan_entry___last_ticks_91 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            2u,
            "%s: p_sup_chan_entry is NULL",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "reg_get_superchan_entry");
          reg_get_superchan_entry___last_ticks_91 = v24;
        }
      }
    }
    else
    {
      v23 = jiffies;
      if ( reg_get_superchan_entry___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: pdev reg component is NULL",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "reg_get_superchan_entry");
        reg_get_superchan_entry___last_ticks = v23;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: super channel idx is invalid for the chan_enum %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "reg_get_superchan_entry",
      a2);
  }
  return 4;
}
