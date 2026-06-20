__int64 __fastcall reg_get_band_channel_list(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( pdev_obj )
    return reg_get_band_from_cur_chan_list(a2, a3, pdev_obj, 0);
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: reg pdev priv obj is NULL",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "reg_get_band_channel_list");
  return 0;
}
