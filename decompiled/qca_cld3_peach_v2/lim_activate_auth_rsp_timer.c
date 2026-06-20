__int64 __fastcall lim_activate_auth_rsp_timer(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = tx_timer_activate((char *)(a2 + 280));
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: could not activate auth rsp timer",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "lim_activate_auth_rsp_timer");
  return result;
}
