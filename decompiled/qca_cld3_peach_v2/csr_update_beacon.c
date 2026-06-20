__int64 csr_update_beacon()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v9[1], 0, 40);
  v9[0] = 5059;
  result = scheduler_post_message_debug(0x34u, 0x35u, 53, (unsigned __int16 *)v9, 0x404u, (__int64)"csr_update_beacon");
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: scheduler_post_message failed, status = %u",
               v1,
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               "csr_update_beacon",
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
