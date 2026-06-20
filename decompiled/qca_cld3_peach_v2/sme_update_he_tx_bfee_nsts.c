__int64 __fastcall sme_update_he_tx_bfee_nsts(
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
  if ( a2 <= 5u && *(_QWORD *)(a1 + 17296) + 96LL * a2 )
  {
    if ( a3 <= 7u )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1317LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1317LL) & 0xFFFFFFFFFFC7FFFFLL
                                                | ((unsigned __int64)a3 << 19);
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1317LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1317LL) & 0xFFFFFFFFF8FFFFFFLL
                                                | ((unsigned __int64)a3 << 24);
      csr_update_session_he_cap(a1);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: No session for id %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_he_tx_bfee_nsts");
  }
  return 4294967274LL;
}
