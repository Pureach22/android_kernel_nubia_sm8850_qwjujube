__int64 __fastcall qcom_vadc5_scale_hw_calib_current(unsigned int *a1, __int64 a2, __int16 a3, _DWORD *a4)
{
  int v4; // w8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 result; // x0
  __int64 v8; // x8

  LOWORD(v4) = a3;
  if ( a3 < 0 )
    v4 = -a3;
  v6 = *a1;
  v5 = a1[1];
  result = 0;
  v8 = (__int64)(1000 * (__int16)v4 * (unsigned __int64)*(unsigned int *)(a2 + 12)) / 0x7FFF * v5 / v6;
  if ( a3 < 0 )
    LODWORD(v8) = -(int)v8;
  *a4 = v8;
  return result;
}
