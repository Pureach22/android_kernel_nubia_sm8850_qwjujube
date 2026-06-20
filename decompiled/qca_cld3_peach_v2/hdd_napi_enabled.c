_QWORD *__fastcall hdd_napi_enabled(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  __int64 v11; // x1

  result = _cds_get_context(61, (__int64)"hdd_napi_enabled", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    if ( a1 == -1 )
      v11 = 0xFFFFFFFFLL;
    else
      v11 = (unsigned int)(a1 - 1);
    return (_QWORD *)hif_napi_enabled(result, v11);
  }
  return result;
}
