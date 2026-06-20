__int64 __fastcall qcom_adc5_prescaling_from_dt(int a1, int a2)
{
  __int64 result; // x0
  _DWORD *i; // x9

  result = 0;
  for ( i = &unk_7FFC; *(i - 1) != a1 || *i != a2; i += 2 )
  {
    if ( ++result == 19 )
      return 4294967274LL;
  }
  if ( (_DWORD)result != 19 )
    return result;
  return 4294967274LL;
}
