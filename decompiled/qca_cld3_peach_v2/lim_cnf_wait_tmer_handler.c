__int64 __fastcall lim_cnf_wait_tmer_handler(__int64 a1)
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
  memset(&v10[1], 0, 40);
  v10[0] = 5095;
  result = lim_post_msg_api(a1, (unsigned __int16 *)v10);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: posting to LIM failed, reason: %d",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "lim_cnf_wait_tmer_handler",
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
