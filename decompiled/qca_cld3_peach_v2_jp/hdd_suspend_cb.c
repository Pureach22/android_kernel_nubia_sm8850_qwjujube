_QWORD *__fastcall hdd_suspend_cb(
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
  __int64 v9; // x1

  result = _cds_get_context(51, (__int64)"hdd_suspend_cb", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
    return (_QWORD *)complete(result + 19, v9);
  return result;
}
