__int64 __fastcall qcom_scm_iommu_secure_ptbl_size(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
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
  __int64 v13; // [xsp+8h] [xbp-88h] BYREF
  __int64 v14; // [xsp+10h] [xbp-80h]
  __int64 v15; // [xsp+18h] [xbp-78h]
  __int64 v16; // [xsp+20h] [xbp-70h] BYREF
  int v17; // [xsp+28h] [xbp-68h]
  int v18; // [xsp+2Ch] [xbp-64h]
  __int64 v19; // [xsp+30h] [xbp-60h]
  __int64 v20; // [xsp+38h] [xbp-58h]
  __int64 v21; // [xsp+40h] [xbp-50h]
  __int64 v22; // [xsp+48h] [xbp-48h]
  __int64 v23; // [xsp+50h] [xbp-40h]
  __int64 v24; // [xsp+58h] [xbp-38h]
  __int64 v25; // [xsp+60h] [xbp-30h]
  __int64 v26; // [xsp+68h] [xbp-28h]
  __int64 v27; // [xsp+70h] [xbp-20h]
  __int64 v28; // [xsp+78h] [xbp-18h]
  int v29; // [xsp+80h] [xbp-10h]
  int v30; // [xsp+84h] [xbp-Ch]
  __int64 v31; // [xsp+88h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v30 = 0;
  v16 = 0x30000000CLL;
  v18 = 0;
  v17 = 1;
  v19 = (unsigned int)a1;
  v29 = 2;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v14 = 0;
  v15 = 0;
  v13 = 0;
  v9 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) < 2 )
  {
    LODWORD(result) = _scm_smc_call(v9, &v16, qcom_scm_convention, &v13, 0);
    if ( !a2 )
      goto LABEL_7;
    goto LABEL_6;
  }
  if ( convention == 1 )
  {
    LODWORD(result) = scm_legacy_call(v9, (__int64)&v16, &v13);
    if ( !a2 )
      goto LABEL_7;
    goto LABEL_6;
  }
  printk(&unk_124E9, "qcom_scm_call", v11);
  LODWORD(result) = -22;
  if ( a2 )
LABEL_6:
    *a2 = v13;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  if ( (_DWORD)result )
    return (unsigned int)result;
  else
    return (unsigned int)v14;
}
