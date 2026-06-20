__int64 csr_sta_continue_csa()
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
  v9[0] = 5273;
  result = scheduler_post_message_debug(
             0x34u,
             0x35u,
             53,
             (unsigned __int16 *)v9,
             0x1D17u,
             (__int64)"csr_sta_continue_csa");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: eWNI_SME_STA_CSA_CONTINUE_REQ failed!(err=%d)",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "csr_sta_continue_csa",
      (unsigned int)result);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
