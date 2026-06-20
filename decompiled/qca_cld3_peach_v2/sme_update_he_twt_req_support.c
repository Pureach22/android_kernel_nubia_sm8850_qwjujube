__int64 __fastcall sme_update_he_twt_req_support(
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
  unsigned __int64 v11; // x13
  unsigned __int64 v13; // x10

  if ( a2 <= 5u && a1[2162] + 96LL * a2 )
  {
    if ( a3 )
    {
      *(_QWORD *)(a1[1] + 1309LL) = *(_QWORD *)(a1[1] + 1309LL) & 0xFFFFFFFFFFFFFFFDLL
                                  | (2 * ((*(_QWORD *)(a1[1] + 1369LL) >> 1) & 1LL));
      v11 = *(_QWORD *)((char *)a1 + 21849) & 0xFFFFFFFFFFFFFFFDLL
          | (2 * ((*(_QWORD *)((char *)a1 + 21969) >> 1) & 1LL));
      *(_QWORD *)((char *)a1 + 21789) = *(_QWORD *)((char *)a1 + 21789) & 0xFFFFFFFFFFFFFFFDLL
                                      | (2 * ((*(_QWORD *)((char *)a1 + 21909) >> 1) & 1LL));
      *(_QWORD *)((char *)a1 + 21849) = v11;
    }
    else
    {
      *(_QWORD *)(a1[1] + 1309LL) &= ~2uLL;
      v13 = *(_QWORD *)((char *)a1 + 21849) & 0xFFFFFFFFFFFFFFFDLL;
      *(_QWORD *)((char *)a1 + 21789) &= ~2uLL;
      *(_QWORD *)((char *)a1 + 21849) = v13;
    }
    ucfg_twt_cfg_set_requestor(a1[2703], a3 != 0);
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
      "sme_update_he_twt_req_support");
    return 4294967274LL;
  }
}
