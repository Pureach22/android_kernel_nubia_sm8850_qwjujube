unsigned __int8 *__fastcall calibrate_8960(__int64 *a1)
{
  unsigned __int64 v1; // x23
  __int64 v3; // x0
  unsigned __int8 *result; // x0
  int v5; // w8
  int v6; // w10
  int v7; // w10
  int v8; // w9
  int v9; // w9
  int v10; // w9
  int v11; // w10
  int v12; // w10
  int v13; // w9
  int v14; // w9
  int v15; // w9
  int v16; // w9
  unsigned __int8 *v17; // x20
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  int v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  result = (unsigned __int8 *)qfprom_read(v3, "calib");
  if ( (unsigned __int64)result >= 0xFFFFFFFFFFFFF001LL )
    result = (unsigned __int8 *)qfprom_read(*a1, "calib_backup");
  if ( (unsigned __int64)result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_17;
  v5 = *((_DWORD *)a1 + 2);
  if ( !v5 )
    goto LABEL_16;
  v6 = *result;
  *((_DWORD *)a1 + 668) = 826;
  LODWORD(v18) = v6;
  if ( v5 == 1 )
    goto LABEL_16;
  v7 = result[1];
  *((_DWORD *)a1 + 690) = 826;
  HIDWORD(v18) = v7;
  if ( v5 == 2 )
    goto LABEL_16;
  v8 = result[2];
  *((_DWORD *)a1 + 712) = 804;
  LODWORD(v19) = v8;
  if ( v5 == 3 )
    goto LABEL_16;
  v9 = result[3];
  *((_DWORD *)a1 + 734) = 826;
  HIDWORD(v19) = v9;
  if ( v5 == 4 )
    goto LABEL_16;
  v10 = result[4];
  *((_DWORD *)a1 + 756) = 761;
  LODWORD(v20) = v10;
  if ( v5 == 5 )
    goto LABEL_16;
  v11 = result[5];
  *((_DWORD *)a1 + 778) = 782;
  HIDWORD(v20) = v11;
  if ( v5 == 6 )
    goto LABEL_16;
  v12 = result[6];
  *((_DWORD *)a1 + 800) = 782;
  LODWORD(v21) = v12;
  if ( v5 == 7 )
    goto LABEL_16;
  v13 = result[7];
  *((_DWORD *)a1 + 822) = 849;
  HIDWORD(v21) = v13;
  if ( v5 == 8 )
    goto LABEL_16;
  v14 = result[8];
  *((_DWORD *)a1 + 844) = 782;
  LODWORD(v22) = v14;
  if ( v5 == 9
    || (v15 = result[9], *((_DWORD *)a1 + 866) = 849, HIDWORD(v22) = v15, v5 == 10)
    || (v16 = result[10], *((_DWORD *)a1 + 888) = 782, v23 = v16, v5 == 11) )
  {
LABEL_16:
    v17 = result;
    compute_intercept_slope(a1, &v18, 0, 1);
    kfree(v17);
    result = nullptr;
LABEL_17:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 0, 14, 6, 2), v1);
  return (unsigned __int8 *)enable_8960();
}
