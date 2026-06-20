__int64 __fastcall sme_update_eht_scs_traffic_desc_support(
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
  __int64 v11; // x1
  __int64 v12; // x10
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x10

  if ( a2 <= 5u && (v11 = a1[2162] + 96LL * a2) != 0 )
  {
    v12 = 32 * (a3 & 1u);
    *(_QWORD *)(a1[1] + 1501LL) = *(_QWORD *)(a1[1] + 1501LL) & 0xFFFFFFFFFFFFFFDFLL | v12;
    v13 = *(_QWORD *)((char *)a1 + 22065) & 0xFFFFFFFFFFFFFFDFLL | v12;
    v14 = *(_QWORD *)((char *)a1 + 22157) & 0xFFFFFFFFFFFFFFDFLL | v12;
    *(_QWORD *)((char *)a1 + 22065) = v13;
    *(_QWORD *)((char *)a1 + 22157) = v14;
    csr_update_session_eht_cap(a1, v11);
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
      "sme_update_eht_scs_traffic_desc_support");
    return 4294967274LL;
  }
}
