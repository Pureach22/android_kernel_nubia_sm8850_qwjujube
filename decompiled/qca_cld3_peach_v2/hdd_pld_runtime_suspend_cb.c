__int64 __fastcall hdd_pld_runtime_suspend_cb(
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

  context = _cds_get_context(64, (__int64)"hdd_pld_runtime_suspend_cb", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
    return pld_auto_suspend(context[5]);
  else
    return 4294967274LL;
}
