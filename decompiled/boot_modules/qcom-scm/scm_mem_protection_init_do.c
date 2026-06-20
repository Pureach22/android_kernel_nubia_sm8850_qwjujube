__int64 __fastcall scm_mem_protection_init_do(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  int convention; // w0
  __int64 v10; // x2
  unsigned int v11; // w0
  unsigned int v12; // w19
  __int64 result; // x0
  unsigned int v14; // w20
  _QWORD v15[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v16[2]; // [xsp+20h] [xbp-70h] BYREF
  __int64 v17; // [xsp+30h] [xbp-60h]
  __int64 v18; // [xsp+38h] [xbp-58h]
  __int64 v19; // [xsp+40h] [xbp-50h]
  __int64 v20; // [xsp+48h] [xbp-48h]
  __int64 v21; // [xsp+50h] [xbp-40h]
  __int64 v22; // [xsp+58h] [xbp-38h]
  __int64 v23; // [xsp+60h] [xbp-30h]
  __int64 v24; // [xsp+68h] [xbp-28h]
  __int64 v25; // [xsp+70h] [xbp-20h]
  __int64 v26; // [xsp+78h] [xbp-18h]
  int v27; // [xsp+80h] [xbp-10h]
  int v28; // [xsp+84h] [xbp-Ch]
  __int64 v29; // [xsp+88h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v28 = 0;
  v16[0] = 0x700000019LL;
  v17 = 0;
  v16[1] = 2;
  v27 = 2;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  memset(v15, 0, sizeof(v15));
  if ( _scm )
  {
    v17 = 1800;
    v18 = 2320;
    v8 = *(_QWORD *)_scm;
    convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v10);
        printk(&unk_12343, "scm_mem_protection_init_do", 4294967274LL);
        result = 4294967274LL;
        goto LABEL_8;
      }
      v11 = scm_legacy_call(v8, (__int64)v16, v15);
    }
    else
    {
      v11 = _scm_smc_call(v8, v16, qcom_scm_convention, v15, 0);
    }
    v12 = v15[0];
    if ( v11 | LODWORD(v15[0]) )
    {
      v14 = v11;
      printk(&unk_12343, "scm_mem_protection_init_do", v11);
      if ( v14 )
        result = v14;
      else
        result = v12;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    printk(&unk_1292D, "scm_mem_protection_init_do", a3);
    result = 0xFFFFFFFFLL;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
