__int64 __fastcall wma_echo_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v17[1], 0, 40);
  v17[0] = 5272;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Received Echo reply from firmware!",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wma_echo_event_handler");
  result = scheduler_post_message_debug(
             0x36u,
             0x34u,
             52,
             (unsigned __int16 *)v17,
             0x4Eu,
             (__int64)"wma_echo_event_handler");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Fail to post fw state reply msg",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wma_echo_event_handler");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
