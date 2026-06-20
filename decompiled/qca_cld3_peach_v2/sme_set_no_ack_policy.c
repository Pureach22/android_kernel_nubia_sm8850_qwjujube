__int64 __fastcall sme_set_no_ack_policy(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  _BOOL4 v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v23, 0, 48);
  if ( a4 < 5u )
  {
    v14 = a3 != 0;
    if ( a4 == 4 )
      *(_DWORD *)(a1 + 21697) = 16843009 * v14;
    else
      *(_BYTE *)(a1 + a4 + 21697) = v14;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: no ack is set to %d for ac %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_set_no_ack_policy",
      a3 != 0);
    qdf_mem_set(v23, 0x30u, 0);
    LODWORD(v23[0]) = 5266;
    HIDWORD(v23[0]) = a2;
    result = scheduler_post_message_debug(
               0x34u,
               0x35u,
               53,
               (unsigned __int16 *)v23,
               0x20FFu,
               (__int64)"sme_set_no_ack_policy");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post update edca profile",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_set_no_ack_policy");
      result = 4294967291LL;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: invalid ac val %d", a5, a6, a7, a8, a9, a10, a11, a12, "sme_set_no_ack_policy", a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
