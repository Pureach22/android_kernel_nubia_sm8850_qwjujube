__int64 __fastcall qcom_scm_ice_available(
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
  __int64 v28; // x19
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  int v36; // w0
  __int64 v37; // x2
  int v38; // w0
  bool v39; // zf
  void *v40; // x0
  const char *v41; // x1
  __int64 v42; // [xsp+8h] [xbp-88h] BYREF
  __int64 v43; // [xsp+10h] [xbp-80h]
  __int64 v44; // [xsp+18h] [xbp-78h]
  __int64 v45; // [xsp+20h] [xbp-70h] BYREF
  __int64 v46; // [xsp+28h] [xbp-68h]
  __int64 v47; // [xsp+30h] [xbp-60h]
  __int64 v48; // [xsp+38h] [xbp-58h]
  __int64 v49; // [xsp+40h] [xbp-50h]
  __int64 v50; // [xsp+48h] [xbp-48h]
  __int64 v51; // [xsp+50h] [xbp-40h]
  __int64 v52; // [xsp+58h] [xbp-38h]
  __int64 v53; // [xsp+60h] [xbp-30h]
  __int64 v54; // [xsp+68h] [xbp-28h]
  __int64 v55; // [xsp+70h] [xbp-20h]
  __int64 v56; // [xsp+78h] [xbp-18h]
  int v57; // [xsp+80h] [xbp-10h]
  int v58; // [xsp+84h] [xbp-Ch]
  __int64 v59; // [xsp+88h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)_scm;
  v56 = 0;
  v58 = 0;
  v54 = 0;
  v55 = 0;
  v44 = 0;
  v45 = 0x100000006LL;
  v57 = 2;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v47 = 0;
  v42 = 0;
  v43 = 0;
  v46 = 1;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
    goto LABEL_20;
  v47 = qword_136C0[(unsigned int)(convention - 1)];
  v17 = _get_convention(convention, v10, v11, v12, v13, v14, v15, v16);
  if ( (unsigned int)(v17 - 2) >= 2 )
  {
    if ( v17 != 1 )
    {
      v40 = &unk_124E9;
      v41 = "qcom_scm_call";
      goto LABEL_21;
    }
    v18 = scm_legacy_call(v8, (__int64)&v45, &v42);
  }
  else
  {
    v18 = _scm_smc_call(v8, &v45, qcom_scm_convention, &v42, 0);
  }
  v26 = v18;
  result = 0;
  if ( v26 || !v42 )
    goto LABEL_19;
  v28 = *(_QWORD *)_scm;
  v56 = 0;
  v58 = 0;
  v54 = 0;
  v55 = 0;
  v44 = 0;
  v45 = 0x100000006LL;
  v57 = 2;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v47 = 0;
  v42 = 0;
  v43 = 0;
  v46 = 1;
  v29 = _get_convention(0, v19, v20, v21, v22, v23, v24, v25);
  if ( (unsigned int)(v29 - 1) >= 3 )
  {
LABEL_20:
    v40 = &unk_1227A;
    v41 = "__qcom_scm_is_call_available";
LABEL_21:
    printk(v40, v41, v11);
    result = 0;
    goto LABEL_19;
  }
  v47 = qword_136D8[(unsigned int)(v29 - 1)];
  v36 = _get_convention(v29, v30, v11, v31, v32, v33, v34, v35);
  if ( (unsigned int)(v36 - 2) >= 2 )
  {
    if ( v36 == 1 )
    {
      v38 = scm_legacy_call(v28, (__int64)&v45, &v42);
    }
    else
    {
      printk(&unk_124E9, "qcom_scm_call", v37);
      v38 = -22;
    }
  }
  else
  {
    v38 = _scm_smc_call(v28, &v45, qcom_scm_convention, &v42, 0);
  }
  if ( v38 )
    v39 = 1;
  else
    v39 = v42 == 0;
  result = !v39;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
