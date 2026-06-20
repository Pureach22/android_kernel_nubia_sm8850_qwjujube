__int64 __fastcall sme_update_mu_edca_params(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, 48);
  qdf_mem_set(v12, 0x30u, 0);
  LODWORD(v12[0]) = 5267;
  HIDWORD(v12[0]) = a2;
  result = scheduler_post_message_debug(
             0x34u,
             0x35u,
             53,
             (unsigned __int16 *)v12,
             0x2D54u,
             (__int64)"sme_update_mu_edca_params");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Not able to post update edca profile",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "sme_update_mu_edca_params");
    result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
