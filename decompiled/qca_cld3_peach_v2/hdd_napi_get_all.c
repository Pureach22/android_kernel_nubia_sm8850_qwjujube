_QWORD *__fastcall hdd_napi_get_all(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *result; // x0

  result = _cds_get_context(61, (__int64)"hdd_napi_get_all", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
    return (_QWORD *)hif_napi_get_all();
  return result;
}
