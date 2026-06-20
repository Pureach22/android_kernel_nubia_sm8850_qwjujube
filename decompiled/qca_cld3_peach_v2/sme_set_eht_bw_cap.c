__int64 __fastcall sme_set_eht_bw_cap(
        _QWORD *a1,
        unsigned __int8 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  unsigned __int64 *v13; // x8
  unsigned __int64 v14; // x9

  if ( a2 > 5u )
    return qdf_trace_msg(0x34u, 8u, "%s: No session for id %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_eht_bw_cap");
  v11 = a1[2162] + 96LL * a2;
  if ( !v11 )
    return qdf_trace_msg(0x34u, 8u, "%s: No session for id %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_eht_bw_cap");
  if ( a3 > 4 )
  {
    qdf_trace_msg(0x34u, 8u, "%s: Config EHT caps", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_eht_bw_cap");
    v13 = (unsigned __int64 *)(a1[1] + 1501LL);
    v14 = *v13 | 0x20000;
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Reset 320M support as chan width is %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_set_eht_bw_cap",
      a3);
    v13 = (unsigned __int64 *)(a1[1] + 1501LL);
    v14 = *v13 & 0xFFFFFFFFFFFDFFFFLL;
  }
  *v13 = v14;
  qdf_mem_copy((char *)a1 + 22156, (const void *)(a1[1] + 1500LL), 0x5Cu);
  return csr_update_session_eht_cap(a1, v11);
}
