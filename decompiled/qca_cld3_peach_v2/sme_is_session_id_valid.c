bool __fastcall sme_is_session_id_valid(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8

  if ( a1 )
    return a2 < 6 && (v12 = *(_QWORD *)(a1 + 17296)) != 0 && (*(_BYTE *)(v12 + 96LL * a2 + 1) & 1) != 0;
  qdf_trace_msg(0x34u, 2u, "%s: null mac pointer", a3, a4, a5, a6, a7, a8, a9, a10, "sme_is_session_id_valid", v10, v11);
  return 0;
}
