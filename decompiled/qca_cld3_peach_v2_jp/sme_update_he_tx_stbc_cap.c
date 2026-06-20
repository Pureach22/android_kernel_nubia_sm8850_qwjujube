__int64 __fastcall sme_update_he_tx_stbc_cap(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a2 <= 5u && *(_QWORD *)(a1 + 17224) + 96LL * a2 )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) & 0xFFFFFFFFFFFFFFF7LL
                                              | (8LL * (a3 != 0));
    *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) & 0xFFFDFFFFFFFFFFFFLL
                                              | ((unsigned __int64)(a3 != 0) << 49);
    csr_update_session_he_cap(a1);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: No session for id %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_he_tx_stbc_cap");
    return 4294967274LL;
  }
}
