__int64 __fastcall lim_post_csa_ocv_sa_query_timer_init(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19

  if ( !a1 )
    return 5;
  result = qdf_mc_timer_init(a1 + 9800, 0, (__int64)lim_post_csa_ocv_sa_query_timer_handler, a1);
  if ( (_DWORD)result )
  {
    v10 = result;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Fail to init post csa ocv sa query timer",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "lim_post_csa_ocv_sa_query_timer_init");
    return v10;
  }
  return result;
}
