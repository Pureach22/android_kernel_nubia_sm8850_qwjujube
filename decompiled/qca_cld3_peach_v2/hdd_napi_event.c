__int64 __fastcall hdd_napi_event(
        unsigned int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0

  context = _cds_get_context(61, (__int64)"hdd_napi_event", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
    return hif_napi_event(context, a1, a2);
  else
    return 4294967282LL;
}
