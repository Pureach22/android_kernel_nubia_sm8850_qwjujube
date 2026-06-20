__int64 reg_is_freq_indoor()
{
  __int64 reg_chan; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  reg_chan = reg_get_reg_chan();
  if ( reg_chan )
    return (*(unsigned __int8 *)(reg_chan + 13) >> 1) & 1;
  qdf_trace_msg(0x51u, 2u, "%s: reg channel is NULL", v1, v2, v3, v4, v5, v6, v7, v8, "reg_is_freq_indoor");
  return 0;
}
