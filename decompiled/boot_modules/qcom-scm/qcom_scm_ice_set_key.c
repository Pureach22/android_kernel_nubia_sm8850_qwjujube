__int64 __fastcall qcom_scm_ice_set_key(
        unsigned int a1,
        const void *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  size_t v5; // x19
  __int64 v7; // x0
  void *v8; // x0
  void *v9; // x20
  __int64 v10; // x21
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  int convention; // w0
  __int64 v19; // x2
  unsigned int v20; // w0
  unsigned int v21; // w21
  _QWORD v23[3]; // [xsp+0h] [xbp-70h] BYREF
  __int64 v24; // [xsp+18h] [xbp-58h]
  __int64 v25; // [xsp+20h] [xbp-50h]
  __int64 v26; // [xsp+28h] [xbp-48h]
  __int64 v27; // [xsp+30h] [xbp-40h]
  __int64 v28; // [xsp+38h] [xbp-38h]
  __int64 v29; // [xsp+40h] [xbp-30h]
  __int64 v30; // [xsp+48h] [xbp-28h]
  __int64 v31; // [xsp+50h] [xbp-20h]
  __int64 v32; // [xsp+58h] [xbp-18h]
  __int64 v33; // [xsp+60h] [xbp-10h]
  __int64 v34; // [xsp+68h] [xbp-8h]

  v5 = a3;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0x400000010LL;
  v23[1] = 133;
  v23[2] = a1;
  v24 = 0;
  v25 = a3;
  v26 = a4;
  v27 = a5;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v7 = *(_QWORD *)(_scm + 344);
  v31 = 0;
  v32 = 0;
  v33 = 2;
  v8 = (void *)qcom_tzmem_alloc(v7, a3, 3264);
  if ( v8 )
  {
    v9 = v8;
    memcpy(v8, a2, v5);
    v24 = qcom_tzmem_to_phys(v9);
    v10 = *(_QWORD *)_scm;
    convention = _get_convention(v24, v11, v12, v13, v14, v15, v16, v17);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v19);
        v21 = -22;
        goto LABEL_8;
      }
      v20 = scm_legacy_call(v10, (__int64)v23, nullptr);
    }
    else
    {
      v20 = _scm_smc_call(v10, v23, qcom_scm_convention, nullptr, 0);
    }
    v21 = v20;
LABEL_8:
    memset(v9, 0, v5);
    qcom_tzmem_free(v9);
    goto LABEL_9;
  }
  v21 = -12;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v21;
}
