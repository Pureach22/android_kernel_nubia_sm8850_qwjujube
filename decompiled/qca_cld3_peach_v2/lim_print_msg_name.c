__int64 __fastcall lim_print_msg_name(__int64 a1, __int64 a2, int a3)
{
  const char *v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v3 = lim_msg_str(a3);
  return qdf_trace_msg(0x35u, 8u, "%s: Msg: %s", v4, v5, v6, v7, v8, v9, v10, v11, "lim_print_msg_name", v3);
}
