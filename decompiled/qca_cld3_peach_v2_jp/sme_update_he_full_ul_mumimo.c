__int64 __fastcall sme_update_he_full_ul_mumimo(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x22
  unsigned __int64 v14; // x11

  if ( a2 <= 5u && *(_QWORD *)(a1 + 17224) + 96LL * a2 )
  {
    v12 = a1 + 20480;
    qdf_trace_msg(0x34u, 4u, "%s: UL MU mimo: %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_he_full_ul_mumimo", a3);
    *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) & 0xFFFFFFFFFFFFFE7FLL
                                              | ((unsigned __int64)(a3 & 3) << 7);
    v14 = *(_QWORD *)(v12 + 1305) & 0xFFFFFFFFFFFFFE7FLL | ((unsigned __int64)(a3 & 3) << 7);
    *(_QWORD *)(v12 + 1245) = *(_QWORD *)(v12 + 1245) & 0xFFFFFFFFFFFFFE7FLL | ((unsigned __int64)(a3 & 3) << 7);
    *(_QWORD *)(v12 + 1305) = v14;
    csr_update_session_he_cap(a1);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: No session for id %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_he_full_ul_mumimo");
    return 4294967274LL;
  }
}
