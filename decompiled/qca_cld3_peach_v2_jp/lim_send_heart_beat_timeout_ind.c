__int64 __fastcall lim_send_heart_beat_timeout_ind(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[1] = a10;
  memset(&v19[2], 0, 32);
  v19[0] = 5079;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Heartbeat failure from Fw",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "lim_send_heart_beat_timeout_ind");
  result = scheduler_post_message_debug(0x35u, 0x35u, 53, (unsigned __int16 *)v19, 0x4DAu, (__int64)"lim_post_msg_api");
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: posting message: %X to LIM failed, reason: %d",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "lim_send_heart_beat_timeout_ind",
               LOWORD(v19[0]),
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
