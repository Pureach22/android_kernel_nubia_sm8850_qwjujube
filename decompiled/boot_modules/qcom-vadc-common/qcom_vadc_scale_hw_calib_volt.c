__int64 __fastcall qcom_vadc_scale_hw_calib_volt(unsigned int *a1, __int64 a2, __int16 a3, _DWORD *a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x8

  v4 = 1875000LL * (a3 & (unsigned int)~(a3 >> 31));
  v5 = *(unsigned int *)(a2 + 8);
  if ( v4 >= v5 )
    v6 = (__int64)(v4 / v5 * a1[1]) / *a1;
  else
    LODWORD(v6) = 0;
  *a4 = v6;
  return 0;
}
