__int64 __fastcall csr_mlme_get_concurrent_operation_freq(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0

  context = _cds_get_context(52, (__int64)"csr_mlme_get_concurrent_operation_freq", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
    return csr_get_concurrent_operation_freq((__int64)context);
  else
    return 16;
}
