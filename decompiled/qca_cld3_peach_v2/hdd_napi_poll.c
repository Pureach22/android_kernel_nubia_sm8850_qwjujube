__int64 __fastcall hdd_napi_poll(
        __int64 a1,
        unsigned int a2,
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

  context = _cds_get_context(61, (__int64)"hdd_napi_poll", a3, a4, a5, a6, a7, a8, a9, a10);
  return hif_napi_poll(context, a1, a2);
}
