__int64 __fastcall qcom_adc5_gen3_scale_hw_calib_usb_in_current(unsigned int *a1, __int64 a2, __int16 a3, _DWORD *a4)
{
  int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 result; // x0
  __int64 v9; // x8

  LOWORD(v4) = a3;
  if ( a3 < 0 )
    v4 = -a3;
  v5 = (unsigned __int128)(1000000LL * (__int16)v4 * (__int128)0xE2C4A6886A4C2E1LL) >> 64;
  v7 = *a1;
  v6 = a1[1];
  result = 0;
  v9 = (__int64)(((v5 >> 9) + ((unsigned __int64)v5 >> 63)) * v6) / v7;
  if ( a3 < 0 )
    LODWORD(v9) = -(int)v9;
  *a4 = v9;
  return result;
}
