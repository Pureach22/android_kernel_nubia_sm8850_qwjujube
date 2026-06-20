__int64 __fastcall qcom_vadc_scale_hw_calib_current_raw(int *a1, __int64 a2, __int16 a3, _DWORD *a4)
{
  __int64 v4; // x9

  v4 = *a1;
  if ( !(_DWORD)v4 )
    return 4294967274LL;
  *a4 = (unsigned int)a1[1] * (__int64)a3 / v4;
  return 0;
}
