__int64 __fastcall sme_change_mcc_beacon_interval(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x20
  __int64 result; // x0
  unsigned int v21; // w19

  context = _cds_get_context(52, (__int64)"sme_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context;
    result = qdf_mutex_acquire((__int64)(context + 1597));
    if ( !(_DWORD)result )
    {
      v21 = csr_send_chng_mcc_beacon_interval(v19, a1);
      qdf_mutex_release((__int64)(v19 + 1597));
      return v21;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: mac_ctx is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "sme_change_mcc_beacon_interval");
    return 16;
  }
  return result;
}
