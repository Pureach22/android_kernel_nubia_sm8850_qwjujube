__int64 __fastcall calibrate_8974(_QWORD *a1)
{
  __int64 v2; // x0
  int v3; // w0
  __int64 calibration; // x0
  unsigned int v5; // w20
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x21
  void *v9; // x1
  _QWORD *v10; // x0
  unsigned __int64 v11; // x4
  unsigned __int64 v12; // x5
  __int64 calibration_legacy; // x0
  unsigned int v14; // w22
  int v16; // [xsp+4h] [xbp-CCh] BYREF
  _QWORD v17[5]; // [xsp+8h] [xbp-C8h] BYREF
  int v18; // [xsp+30h] [xbp-A0h]
  _QWORD v19[5]; // [xsp+38h] [xbp-98h] BYREF
  int v20; // [xsp+60h] [xbp-70h]
  _QWORD v21[5]; // [xsp+68h] [xbp-68h] BYREF
  int v22; // [xsp+90h] [xbp-40h]
  _BYTE v23[40]; // [xsp+98h] [xbp-38h] BYREF
  int v24; // [xsp+C0h] [xbp-10h]
  __int64 v25; // [xsp+C8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  v24 = 0;
  memset(v23, 0, sizeof(v23));
  v22 = 0;
  memset(v21, 0, sizeof(v21));
  v16 = 0;
  v3 = nvmem_cell_read_variable_le_u32(v2, "use_backup", &v16);
  if ( v3 == -2 )
  {
    dev_warn(*a1, "Please migrate to separate nvmem cells for calibration data\n");
  }
  else if ( (v3 & 0x80000000) == 0 )
  {
    calibration = tsens_read_calibration(a1, 2, v23, v21, v16 == 3);
    if ( (calibration & 0x80000000) == 0 )
    {
      v5 = calibration;
      fixup_8974_points(calibration, v23, v21);
      compute_intercept_slope(a1, v23, v21, v5);
LABEL_13:
      LODWORD(v6) = 0;
      goto LABEL_14;
    }
  }
  v6 = qfprom_read(*a1, "calib");
  if ( v6 < 0xFFFFFFFFFFFFF001LL )
  {
    v7 = qfprom_read(*a1, "calib_backup");
    v8 = v7;
    if ( v7 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( *(_DWORD *)(v7 + 4) >> 29 == 3 )
      {
        v9 = &tsens_8974_backup_nvmem;
        v10 = a1;
        v11 = v8;
        v12 = v6;
      }
      else
      {
        v9 = &tsens_8974_nvmem;
        v10 = a1;
        v11 = v6;
        v12 = 0;
      }
      calibration_legacy = tsens_read_calibration_legacy(v10, v9, v19, v17, v11, v12);
      v14 = calibration_legacy;
      fixup_8974_points(calibration_legacy, v19, v17);
      compute_intercept_slope(a1, v19, v17, v14);
      kfree(v6);
      kfree(v8);
      goto LABEL_13;
    }
    kfree(v6);
    LODWORD(v6) = v8;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
