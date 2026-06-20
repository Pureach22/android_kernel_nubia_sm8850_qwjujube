__int64 *__fastcall wma_is_both_psd_eirp_support_present_for_sp(
        _BYTE *a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *result; // x0
  char v13; // w8

  result = _cds_get_context(54, (__int64)"wma_is_both_psd_eirp_support_present_for_sp", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    result = (__int64 *)is_both_psd_eirp_support_present_for_sp(*result, a1);
    v13 = (unsigned __int8)result & 1;
  }
  else
  {
    v13 = 0;
  }
  *a2 = v13;
  return result;
}
