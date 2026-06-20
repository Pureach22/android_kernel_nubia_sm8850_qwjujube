__int64 __fastcall lim_activate_cnf_timer(__int64 a1, unsigned __int16 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v3 = 264LL * a2;
  *(_BYTE *)(*(_QWORD *)(a1 + 1336) + v3 + 50) = *(_BYTE *)(a3 + 8);
  result = tx_timer_activate((char *)(*(_QWORD *)(a1 + 1336) + v3));
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: could not activate cnf wait timer",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "lim_activate_cnf_timer");
  return result;
}
