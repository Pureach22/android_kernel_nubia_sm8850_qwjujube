__int64 __fastcall sme_update_tx_bfee_supp(
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
  *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2827LL) = a3 != 0;
  if ( a2 <= 5u && *(_QWORD *)(a1 + 17296) + 96LL * a2 )
  {
    if ( a3 <= 1u )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1317LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1317LL) & 0xFFFFFFFFFFFDFFFFLL
                                                | ((unsigned __int64)a3 << 17);
      csr_update_session_he_cap();
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: No session for id %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_he_tx_bfee_supp");
  }
  return 4294967274LL;
}
