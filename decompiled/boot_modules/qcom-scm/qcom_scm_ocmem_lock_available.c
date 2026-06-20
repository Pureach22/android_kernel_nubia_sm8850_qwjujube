__int64 __fastcall qcom_scm_ocmem_lock_available(
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
  __int64 convention; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  int v17; // w0
  __int64 v18; // x2
  int v19; // w0
  bool v20; // zf
  __int64 result; // x0
  _QWORD v22[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v23[2]; // [xsp+20h] [xbp-70h] BYREF
  __int64 v24; // [xsp+30h] [xbp-60h]
  __int64 v25; // [xsp+38h] [xbp-58h]
  __int64 v26; // [xsp+40h] [xbp-50h]
  __int64 v27; // [xsp+48h] [xbp-48h]
  __int64 v28; // [xsp+50h] [xbp-40h]
  __int64 v29; // [xsp+58h] [xbp-38h]
  __int64 v30; // [xsp+60h] [xbp-30h]
  __int64 v31; // [xsp+68h] [xbp-28h]
  __int64 v32; // [xsp+70h] [xbp-20h]
  __int64 v33; // [xsp+78h] [xbp-18h]
  int v34; // [xsp+80h] [xbp-10h]
  int v35; // [xsp+84h] [xbp-Ch]
  __int64 v36; // [xsp+88h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)_scm;
  v33 = 0;
  v35 = 0;
  v31 = 0;
  v32 = 0;
  v23[0] = 0x100000006LL;
  v34 = 2;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v24 = 0;
  memset(v22, 0, sizeof(v22));
  v23[1] = 1;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
  {
    printk(&unk_1227A, "__qcom_scm_is_call_available", v11);
    result = 0;
  }
  else
  {
    v24 = qword_136A8[(unsigned int)(convention - 1)];
    v17 = _get_convention(convention, v10, v11, v12, v13, v14, v15, v16);
    if ( (unsigned int)(v17 - 2) >= 2 )
    {
      if ( v17 == 1 )
      {
        v19 = scm_legacy_call(v8, (__int64)v23, v22);
      }
      else
      {
        printk(&unk_124E9, "qcom_scm_call", v18);
        v19 = -22;
      }
    }
    else
    {
      v19 = _scm_smc_call(v8, v23, qcom_scm_convention, v22, 0);
    }
    if ( v19 )
      v20 = 1;
    else
      v20 = v22[0] == 0;
    result = !v20;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
