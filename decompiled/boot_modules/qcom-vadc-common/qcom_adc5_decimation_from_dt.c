__int64 __fastcall qcom_adc5_decimation_from_dt(int a1, _DWORD *a2)
{
  if ( *a2 == a1 )
    return 0;
  if ( a2[1] == a1 )
    return 1;
  if ( a2[2] == a1 )
    return 2;
  return 4294967274LL;
}
