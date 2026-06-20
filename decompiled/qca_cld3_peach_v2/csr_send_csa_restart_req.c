__int64 csr_send_csa_restart_req()
{
  unsigned int v0; // w19
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v10[1], 0, 40);
  v10[0] = 5268;
  v0 = scheduler_post_message_debug(
         0x34u,
         0x35u,
         53,
         (unsigned __int16 *)v10,
         0x1CC9u,
         (__int64)"csr_send_csa_restart_req");
  if ( v0 )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: scheduler_post_msg failed!(err=%d)",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "csr_send_csa_restart_req",
      v0);
  _ReadStatusReg(SP_EL0);
  return v0;
}
