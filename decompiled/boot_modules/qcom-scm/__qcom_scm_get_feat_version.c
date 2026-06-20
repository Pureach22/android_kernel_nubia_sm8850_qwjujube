__int64 __fastcall _qcom_scm_get_feat_version(
        __int64 a1,
        __int64 a2,
        _QWORD *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x20
  int convention; // w0
  __int64 v11; // x2
  __int64 result; // x0
  _QWORD v13[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v14; // [xsp+20h] [xbp-70h] BYREF
  int v15; // [xsp+28h] [xbp-68h]
  int v16; // [xsp+2Ch] [xbp-64h]
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
  v14 = 0x300000006LL;
  v16 = 0;
  v15 = 1;
  v27 = 2;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v17 = a2;
  memset(v13, 0, sizeof(v13));
  v9 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) < 2 )
  {
    result = _scm_smc_call(v9, &v14, qcom_scm_convention, v13, 0);
    if ( !a3 )
      goto LABEL_7;
    goto LABEL_6;
  }
  if ( convention != 1 )
  {
    printk(&unk_124E9, "qcom_scm_call", v11);
    result = 4294967274LL;
    if ( !a3 )
      goto LABEL_7;
    goto LABEL_6;
  }
  result = scm_legacy_call(v9, (__int64)&v14, v13);
  if ( a3 )
LABEL_6:
    *a3 = v13[0];
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
