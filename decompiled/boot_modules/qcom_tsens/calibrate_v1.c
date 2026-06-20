unsigned __int64 __fastcall calibrate_v1(_QWORD *a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  unsigned int calibration_legacy; // w0
  _QWORD v5[5]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v6[6]; // [xsp+30h] [xbp-30h] BYREF

  v6[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v6, 0, 40);
  memset(v5, 0, sizeof(v5));
  result = tsens_calibrate_common();
  if ( (_DWORD)result )
  {
    result = qfprom_read(*a1, "calib");
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v3 = result;
      calibration_legacy = tsens_read_calibration_legacy(a1, &tsens_qcs404_nvmem, v6, v5, result, 0);
      compute_intercept_slope(a1, v6, v5, calibration_legacy);
      kfree(v3);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
