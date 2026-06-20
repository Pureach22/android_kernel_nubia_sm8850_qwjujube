__int64 __fastcall reg_get_max_chwidth(
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
  __int64 reg_chan; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  reg_chan = reg_get_reg_chan(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( reg_chan )
    return *(unsigned __int16 *)(reg_chan + 22);
  qdf_trace_msg(0x51u, 2u, "%s: reg channel is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "reg_get_max_chwidth");
  return 0;
}
