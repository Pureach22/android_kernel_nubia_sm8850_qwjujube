__int64 __fastcall qcom_scm_lmh_dcvsh(int a1, int a2, int a3, __int64 a4, unsigned int a5, __int64 a6)
{
  __int64 v9; // x0
  _DWORD *v10; // x0
  _DWORD *v11; // x19
  __int64 v12; // x20
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  int convention; // w0
  __int64 v21; // x2
  unsigned int v22; // w0
  unsigned int v23; // w20
  _QWORD v25[2]; // [xsp+0h] [xbp-70h] BYREF
  __int64 v26; // [xsp+10h] [xbp-60h]
  __int64 v27; // [xsp+18h] [xbp-58h]
  __int64 v28; // [xsp+20h] [xbp-50h]
  __int64 v29; // [xsp+28h] [xbp-48h]
  __int64 v30; // [xsp+30h] [xbp-40h]
  __int64 v31; // [xsp+38h] [xbp-38h]
  __int64 v32; // [xsp+40h] [xbp-30h]
  __int64 v33; // [xsp+48h] [xbp-28h]
  __int64 v34; // [xsp+50h] [xbp-20h]
  __int64 v35; // [xsp+58h] [xbp-18h]
  __int64 v36; // [xsp+60h] [xbp-10h]
  __int64 v37; // [xsp+68h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0x1000000013LL;
  v25[1] = 21;
  v27 = 20;
  v28 = a4;
  v29 = a5;
  v30 = a6;
  v31 = 0;
  v32 = 0;
  v9 = *(_QWORD *)(_scm + 344);
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 2;
  v10 = (_DWORD *)qcom_tzmem_alloc(v9, 20, 3264);
  if ( v10 )
  {
    v11 = v10;
    *v10 = a1;
    v10[1] = 0;
    v10[2] = a2;
    v10[3] = 1;
    v10[4] = a3;
    v26 = qcom_tzmem_to_phys(v10);
    v12 = *(_QWORD *)_scm;
    convention = _get_convention(v26, v13, v14, v15, v16, v17, v18, v19);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v21);
        v23 = -22;
        goto LABEL_8;
      }
      v22 = scm_legacy_call(v12, (__int64)v25, nullptr);
    }
    else
    {
      v22 = _scm_smc_call(v12, v25, qcom_scm_convention, nullptr, 0);
    }
    v23 = v22;
LABEL_8:
    qcom_tzmem_free(v11);
    goto LABEL_9;
  }
  v23 = -12;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v23;
}
