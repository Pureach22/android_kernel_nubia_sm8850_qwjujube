__int64 __fastcall lim_extract_ies_from_deauth_disassoc(
        __int64 result,
        __int64 a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x0
  _QWORD v12[3]; // [xsp+8h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  if ( result )
  {
    if ( a2 && a3 >= 0x1Bu )
    {
      v11 = *(_QWORD *)(result + 16);
      v12[1] = a2 + 26;
      LODWORD(v12[0]) = a3 - 26;
      result = (__int64)mlme_set_peer_disconnect_ies(v11, (unsigned int *)v12, a4, a5, a6, a7, a8, a9, a10, a11);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: NULL session",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_extract_ies_from_deauth_disassoc");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
