__int64 __fastcall store_max_low_power_cluster_freqs(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v6; // x0
  _QWORD *v7; // x19
  int v8; // w22
  int v9; // w8
  int v10; // w0
  int v11; // w8
  int v12; // w8
  int v13; // w8
  int v14; // w8
  int v15; // w8
  int v16; // w8
  int v17; // w8
  int v18; // w8
  int v19; // w22
  __int64 result; // x0
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v6 = argv_split(3264, a3, (char *)v21 + 4);
  if ( !v6 )
    goto LABEL_30;
  v7 = (_QWORD *)v6;
  v8 = HIDWORD(v21[0]);
  if ( v8 != (unsigned int)_sw_hweight64(*(unsigned int *)(*(_QWORD *)(a1 - 8) + 168LL)) )
  {
    dev_err(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 56LL), "invalid num of low power cpufreqs\n");
    v19 = -22;
    goto LABEL_34;
  }
  v9 = HIDWORD(v21[0]);
  *(_BYTE *)(a1 - 284) = 1;
  if ( !v9 )
    goto LABEL_33;
  v10 = kstrtouint(*v7, 10, v21);
  if ( v10 < 0 )
    goto LABEL_31;
  v11 = v21[0];
  *(_DWORD *)(a1 - 276) = v21[0];
  if ( !v11 )
  {
LABEL_32:
    *(_BYTE *)(a1 - 284) = 0;
    goto LABEL_33;
  }
  if ( HIDWORD(v21[0]) < 2 )
  {
LABEL_33:
    v19 = a4;
    goto LABEL_34;
  }
  v10 = kstrtouint(v7[1], 10, v21);
  if ( v10 < 0 )
  {
LABEL_31:
    v19 = v10;
    goto LABEL_34;
  }
  v12 = v21[0];
  *(_DWORD *)(a1 - 272) = v21[0];
  if ( !v12 )
    goto LABEL_32;
  if ( HIDWORD(v21[0]) < 3 )
    goto LABEL_33;
  v10 = kstrtouint(v7[2], 10, v21);
  if ( v10 < 0 )
    goto LABEL_31;
  v13 = v21[0];
  *(_DWORD *)(a1 - 268) = v21[0];
  if ( !v13 )
    goto LABEL_32;
  if ( HIDWORD(v21[0]) < 4 )
    goto LABEL_33;
  v10 = kstrtouint(v7[3], 10, v21);
  if ( v10 < 0 )
    goto LABEL_31;
  v14 = v21[0];
  *(_DWORD *)(a1 - 264) = v21[0];
  if ( !v14 )
    goto LABEL_32;
  if ( HIDWORD(v21[0]) < 5 )
    goto LABEL_33;
  v10 = kstrtouint(v7[4], 10, v21);
  if ( v10 < 0 )
    goto LABEL_31;
  v15 = v21[0];
  *(_DWORD *)(a1 - 260) = v21[0];
  if ( !v15 )
    goto LABEL_32;
  if ( HIDWORD(v21[0]) < 6 )
    goto LABEL_33;
  v10 = kstrtouint(v7[5], 10, v21);
  if ( v10 < 0 )
    goto LABEL_31;
  v16 = v21[0];
  *(_DWORD *)(a1 - 256) = v21[0];
  if ( !v16 )
    goto LABEL_32;
  if ( HIDWORD(v21[0]) < 7 )
    goto LABEL_33;
  v10 = kstrtouint(v7[6], 10, v21);
  if ( v10 < 0 )
    goto LABEL_31;
  v17 = v21[0];
  *(_DWORD *)(a1 - 252) = v21[0];
  if ( !v17 )
    goto LABEL_32;
  if ( HIDWORD(v21[0]) < 8 )
    goto LABEL_33;
  v10 = kstrtouint(v7[7], 10, v21);
  if ( v10 < 0 )
    goto LABEL_31;
  v18 = v21[0];
  *(_DWORD *)(a1 - 248) = v21[0];
  if ( !v18 )
    goto LABEL_32;
  if ( HIDWORD(v21[0]) < 9 )
    goto LABEL_33;
  v19 = kstrtouint(v7[8], 10, v21);
  if ( v19 < 0 )
  {
LABEL_34:
    argv_free(v7);
    result = v19;
    goto LABEL_35;
  }
  __break(0x5512u);
LABEL_30:
  result = -12;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
