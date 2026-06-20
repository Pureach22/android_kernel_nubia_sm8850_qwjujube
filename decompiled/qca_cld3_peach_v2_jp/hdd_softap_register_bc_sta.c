__int64 __fastcall hdd_softap_register_bc_sta(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w4
  __int64 result; // x0
  __int64 v11; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 259);
  WORD2(v11) = -1;
  LODWORD(v11) = -1;
  if ( v9 < 0x23 )
  {
    result = hdd_softap_register_sta(a1, 0, a2, a3, a4, a5, a6, a7, a8, a9, 0, (__int64)&v11, 0);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error: Invalid sta_id: %u",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_softap_register_bc_sta",
      v11,
      v12);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
