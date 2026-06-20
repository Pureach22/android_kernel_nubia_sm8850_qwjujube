_QWORD *__fastcall hdd_is_cac_in_progress(
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

  result = _cds_get_context(51, (__int64)"hdd_is_cac_in_progress", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
    return (_QWORD *)(*((_BYTE *)result + 912) == 1);
  return result;
}
