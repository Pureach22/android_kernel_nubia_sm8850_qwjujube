__int64 __fastcall sme_ht40_stop_obss_scan(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"sme_ht40_stop_obss_scan", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 16;
  wma_ht40_stop_obss_scan(context, a10);
  return 0;
}
