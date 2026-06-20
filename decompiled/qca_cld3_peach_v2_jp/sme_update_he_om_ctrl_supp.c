__int64 __fastcall sme_update_he_om_ctrl_supp(
        _QWORD *a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v11; // x10

  if ( a2 <= 5u && a1[2153] + 96LL * a2 )
  {
    *(_QWORD *)(a1[1] + 1289LL) = *(_QWORD *)(a1[1] + 1289LL) & 0xFFFFFFFFFDFFFFFFLL
                                | ((unsigned __int64)(a3 & 1) << 25);
    v11 = *(_QWORD *)((char *)a1 + 21777) & 0xFFFFFFFFFDFFFFFFLL | ((unsigned __int64)(a3 & 1) << 25);
    *(_QWORD *)((char *)a1 + 21717) = *(_QWORD *)((char *)a1 + 21717) & 0xFFFFFFFFFDFFFFFFLL
                                    | ((unsigned __int64)(a3 & 1) << 25);
    *(_QWORD *)((char *)a1 + 21777) = v11;
    csr_update_session_he_cap(a1);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: No session for id %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_he_om_ctrl_supp");
    return 4294967274LL;
  }
}
