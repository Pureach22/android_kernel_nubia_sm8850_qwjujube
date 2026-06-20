unsigned __int64 __fastcall calibrate_8916(_QWORD *a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x21
  unsigned __int64 v4; // x20
  unsigned int calibration_legacy; // w0
  _QWORD v6[2]; // [xsp+8h] [xbp-38h] BYREF
  int v7; // [xsp+18h] [xbp-28h]
  _QWORD v8[2]; // [xsp+20h] [xbp-20h] BYREF
  int v9; // [xsp+30h] [xbp-10h]
  __int64 v10; // [xsp+38h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v8[0] = 0;
  v8[1] = 0;
  v7 = 0;
  v6[0] = 0;
  v6[1] = 0;
  result = tsens_calibrate_nvmem(a1, 3);
  if ( (_DWORD)result )
  {
    result = qfprom_read(*a1, "calib");
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v3 = result;
      v4 = qfprom_read(*a1, "calib_sel");
      if ( v4 < 0xFFFFFFFFFFFFF001LL )
      {
        calibration_legacy = tsens_read_calibration_legacy(a1, &tsens_8916_nvmem, v8, v6, v3, v4);
        compute_intercept_slope(a1, v8, v6, calibration_legacy);
        kfree(v3);
        kfree(v4);
        result = 0;
      }
      else
      {
        kfree(v3);
        result = (unsigned int)v4;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
