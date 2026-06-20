__int64 __fastcall qcom_scm_io_readl(
        __int64 a1,
        _DWORD *a2,
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
  int v12; // w0
  _QWORD v14[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v15; // [xsp+20h] [xbp-70h] BYREF
  int v16; // [xsp+28h] [xbp-68h]
  int v17; // [xsp+2Ch] [xbp-64h]
  __int64 v18; // [xsp+30h] [xbp-60h]
  __int64 v19; // [xsp+38h] [xbp-58h]
  __int64 v20; // [xsp+40h] [xbp-50h]
  __int64 v21; // [xsp+48h] [xbp-48h]
  __int64 v22; // [xsp+50h] [xbp-40h]
  __int64 v23; // [xsp+58h] [xbp-38h]
  __int64 v24; // [xsp+60h] [xbp-30h]
  __int64 v25; // [xsp+68h] [xbp-28h]
  __int64 v26; // [xsp+70h] [xbp-20h]
  __int64 v27; // [xsp+78h] [xbp-18h]
  int v28; // [xsp+80h] [xbp-10h]
  int v29; // [xsp+84h] [xbp-Ch]
  __int64 v30; // [xsp+88h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v29 = 0;
  v15 = 0x100000005LL;
  v17 = 0;
  v16 = 1;
  v28 = 2;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = a1;
  memset(v14, 0, sizeof(v14));
  v9 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) < 2 )
  {
    v12 = _scm_smc_call(v9, &v15, qcom_scm_convention, v14, 1);
    if ( v12 < 0 )
      goto LABEL_7;
LABEL_6:
    *a2 = v14[0];
    goto LABEL_7;
  }
  if ( convention != 1 )
  {
    printk(&unk_124E9, "qcom_scm_call_atomic", v11);
    v12 = -22;
    goto LABEL_7;
  }
  v12 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD *))scm_legacy_call_atomic)(v9, &v15, v14);
  if ( (v12 & 0x80000000) == 0 )
    goto LABEL_6;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v12 & (unsigned int)(v12 >> 31);
}
