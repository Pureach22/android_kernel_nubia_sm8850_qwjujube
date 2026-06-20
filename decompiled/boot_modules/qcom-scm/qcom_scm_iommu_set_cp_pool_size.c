__int64 __fastcall qcom_scm_iommu_set_cp_pool_size(
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
  __int64 result; // x0
  __int64 v12; // [xsp+0h] [xbp-70h] BYREF
  int v13; // [xsp+8h] [xbp-68h]
  int v14; // [xsp+Ch] [xbp-64h]
  __int64 v15; // [xsp+10h] [xbp-60h]
  __int64 v16; // [xsp+18h] [xbp-58h]
  int v17; // [xsp+20h] [xbp-50h]
  __int64 v18; // [xsp+24h] [xbp-4Ch]
  __int64 v19; // [xsp+2Ch] [xbp-44h]
  __int64 v20; // [xsp+34h] [xbp-3Ch]
  __int64 v21; // [xsp+3Ch] [xbp-34h]
  __int64 v22; // [xsp+44h] [xbp-2Ch]
  __int64 v23; // [xsp+4Ch] [xbp-24h]
  __int64 v24; // [xsp+54h] [xbp-1Ch]
  int v25; // [xsp+5Ch] [xbp-14h]
  __int64 v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0x50000000CLL;
  v14 = 0;
  v17 = 0;
  v15 = (unsigned int)a2;
  v16 = (unsigned int)a1;
  v13 = 2;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 2;
  v8 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention == 1 )
    {
      result = scm_legacy_call(v8, (__int64)&v12, nullptr);
    }
    else
    {
      printk(&unk_124E9, "qcom_scm_call", v10);
      result = 4294967274LL;
    }
  }
  else
  {
    result = _scm_smc_call(v8, &v12, qcom_scm_convention, nullptr, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
