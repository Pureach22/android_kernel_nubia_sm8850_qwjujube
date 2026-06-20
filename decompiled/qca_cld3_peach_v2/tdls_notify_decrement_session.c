__int64 __fastcall tdls_notify_decrement_session(__int64 a1)
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
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[1] = a1;
  v10[2] = tdls_process_cmd;
  v10[3] = tdls_post_msg_flush_cb;
  v10[4] = 0;
  v10[5] = 0;
  v10[0] = 16;
  result = scheduler_post_message_debug(
             0,
             0,
             72,
             (unsigned __int16 *)v10,
             0x5FEu,
             (__int64)"tdls_process_session_update");
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0,
               1u,
               "%s: message post failed ",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "tdls_process_session_update");
  _ReadStatusReg(SP_EL0);
  return result;
}
