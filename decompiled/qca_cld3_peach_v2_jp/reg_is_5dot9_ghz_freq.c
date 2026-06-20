bool __fastcall reg_is_5dot9_ghz_freq(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
    return (unsigned int)(a2 - 5845) < 0x29;
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: reg pdev priv obj is NULL",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "reg_is_5dot9_ghz_freq");
  return 0;
}
