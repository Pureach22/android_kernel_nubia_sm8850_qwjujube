__int64 __fastcall qcom_scm_dcvs_ca_available(
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
  int v18; // w0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  int v26; // w8
  __int64 result; // x0
  __int64 v28; // x0
  __int64 v29; // x1
  __int64 v30; // x3
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  int v35; // w0
  __int64 v36; // x2
  int v37; // w0
  bool v38; // zf
  void *v39; // x0
  const char *v40; // x1
  __int64 v41; // [xsp+8h] [xbp-88h] BYREF
  __int64 v42; // [xsp+10h] [xbp-80h]
  __int64 v43; // [xsp+18h] [xbp-78h]
  __int64 v44; // [xsp+20h] [xbp-70h] BYREF
  __int64 v45; // [xsp+28h] [xbp-68h]
  __int64 v46; // [xsp+30h] [xbp-60h]
  __int64 v47; // [xsp+38h] [xbp-58h]
  __int64 v48; // [xsp+40h] [xbp-50h]
  __int64 v49; // [xsp+48h] [xbp-48h]
  __int64 v50; // [xsp+50h] [xbp-40h]
  __int64 v51; // [xsp+58h] [xbp-38h]
  __int64 v52; // [xsp+60h] [xbp-30h]
  __int64 v53; // [xsp+68h] [xbp-28h]
  __int64 v54; // [xsp+70h] [xbp-20h]
  __int64 v55; // [xsp+78h] [xbp-18h]
  int v56; // [xsp+80h] [xbp-10h]
  int v57; // [xsp+84h] [xbp-Ch]
  __int64 v58; // [xsp+88h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( _scm )
    v8 = *(_QWORD *)_scm;
  else
    v8 = 0;
  v55 = 0;
  v57 = 0;
  v53 = 0;
  v54 = 0;
  v43 = 0;
  v44 = 0x100000006LL;
  v56 = 2;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v46 = 0;
  v41 = 0;
  v42 = 0;
  v45 = 1;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
    goto LABEL_23;
  v46 = qword_13678[(unsigned int)(convention - 1)];
  v17 = _get_convention(convention, v10, v11, v12, v13, v14, v15, v16);
  if ( (unsigned int)(v17 - 2) >= 2 )
  {
    if ( v17 != 1 )
    {
      v39 = &unk_124E9;
      v40 = "qcom_scm_call";
      goto LABEL_24;
    }
    v18 = scm_legacy_call(v8, (__int64)&v44, &v41);
  }
  else
  {
    v18 = _scm_smc_call(v8, &v44, qcom_scm_convention, &v41, 0);
  }
  v26 = v18;
  result = 0;
  if ( v26 || !v41 )
    goto LABEL_22;
  v55 = 0;
  v57 = 0;
  v53 = 0;
  v54 = 0;
  v43 = 0;
  v44 = 0x100000006LL;
  v56 = 2;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v46 = 0;
  v41 = 0;
  v42 = 0;
  v45 = 1;
  v28 = _get_convention(0, v19, v20, v21, v22, v23, v24, v25);
  if ( (unsigned int)(v28 - 1) >= 3 )
  {
LABEL_23:
    v39 = &unk_1227A;
    v40 = "__qcom_scm_is_call_available";
LABEL_24:
    printk(v39, v40, v11);
    result = 0;
    goto LABEL_22;
  }
  v46 = qword_13690[(unsigned int)(v28 - 1)];
  v35 = _get_convention(v28, v29, v11, v30, v31, v32, v33, v34);
  if ( (unsigned int)(v35 - 2) >= 2 )
  {
    if ( v35 == 1 )
    {
      v37 = scm_legacy_call(v8, (__int64)&v44, &v41);
    }
    else
    {
      printk(&unk_124E9, "qcom_scm_call", v36);
      v37 = -22;
    }
  }
  else
  {
    v37 = _scm_smc_call(v8, &v44, qcom_scm_convention, &v41, 0);
  }
  if ( v37 )
    v38 = 1;
  else
    v38 = v41 == 0;
  result = !v38;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
