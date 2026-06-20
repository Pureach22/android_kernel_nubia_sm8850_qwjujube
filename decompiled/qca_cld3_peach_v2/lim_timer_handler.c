__int64 __fastcall lim_timer_handler(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v20[1], 0, 40);
  v20[0] = a2;
  qdf_trace_msg(0x35u, 8u, "%s: param %X ", a3, a4, a5, a6, a7, a8, a9, a10, "lim_timer_handler", a2);
  result = lim_post_msg_high_priority(a1, (unsigned __int16 *)v20);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: posting message: %X to LIM failed, reason: %d",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "lim_timer_handler",
               LOWORD(v20[0]),
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
