__int64 __fastcall qcom_scm_dcvs_core_available(
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
  int v36; // w0
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x3
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x7
  int v44; // w8
  __int64 v45; // x0
  __int64 v46; // x1
  __int64 v47; // x3
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x7
  int v52; // w0
  __int64 v53; // x2
  int v54; // w0
  void *v55; // x0
  const char *v56; // x1
  bool v57; // zf
  __int64 v58; // [xsp+8h] [xbp-88h] BYREF
  __int64 v59; // [xsp+10h] [xbp-80h]
  __int64 v60; // [xsp+18h] [xbp-78h]
  __int64 v61; // [xsp+20h] [xbp-70h] BYREF
  __int64 v62; // [xsp+28h] [xbp-68h]
  __int64 v63; // [xsp+30h] [xbp-60h]
  __int64 v64; // [xsp+38h] [xbp-58h]
  __int64 v65; // [xsp+40h] [xbp-50h]
  __int64 v66; // [xsp+48h] [xbp-48h]
  __int64 v67; // [xsp+50h] [xbp-40h]
  __int64 v68; // [xsp+58h] [xbp-38h]
  __int64 v69; // [xsp+60h] [xbp-30h]
  __int64 v70; // [xsp+68h] [xbp-28h]
  __int64 v71; // [xsp+70h] [xbp-20h]
  __int64 v72; // [xsp+78h] [xbp-18h]
  int v73; // [xsp+80h] [xbp-10h]
  int v74; // [xsp+84h] [xbp-Ch]
  __int64 v75; // [xsp+88h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( _scm )
    v8 = *(_QWORD *)_scm;
  else
    v8 = 0;
  v72 = 0;
  v74 = 0;
  v70 = 0;
  v71 = 0;
  v60 = 0;
  v61 = 0x100000006LL;
  v73 = 2;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v63 = 0;
  v58 = 0;
  v59 = 0;
  v62 = 1;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
  {
LABEL_21:
    v55 = &unk_1227A;
    v56 = "__qcom_scm_is_call_available";
LABEL_31:
    printk(v55, v56, v11);
    result = 0;
    goto LABEL_32;
  }
  v63 = qword_13630[(unsigned int)(convention - 1)];
  v17 = _get_convention(convention, v10, v11, v12, v13, v14, v15, v16);
  if ( (unsigned int)(v17 - 2) >= 2 )
  {
    if ( v17 != 1 )
      goto LABEL_30;
    v18 = scm_legacy_call(v8, (__int64)&v61, &v58);
  }
  else
  {
    v18 = _scm_smc_call(v8, &v61, qcom_scm_convention, &v58, 0);
  }
  v26 = v18;
  result = 0;
  if ( v26 || !v58 )
    goto LABEL_32;
  v72 = 0;
  v74 = 0;
  v70 = 0;
  v71 = 0;
  v60 = 0;
  v61 = 0x100000006LL;
  v73 = 2;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v63 = 0;
  v58 = 0;
  v59 = 0;
  v62 = 1;
  v28 = _get_convention(0, v19, v20, v21, v22, v23, v24, v25);
  if ( (unsigned int)(v28 - 1) >= 3 )
    goto LABEL_21;
  v63 = qword_13648[(unsigned int)(v28 - 1)];
  v35 = _get_convention(v28, v29, v11, v30, v31, v32, v33, v34);
  if ( (unsigned int)(v35 - 2) >= 2 )
  {
    if ( v35 == 1 )
    {
      v36 = scm_legacy_call(v8, (__int64)&v61, &v58);
      goto LABEL_16;
    }
LABEL_30:
    v55 = &unk_124E9;
    v56 = "qcom_scm_call";
    goto LABEL_31;
  }
  v36 = _scm_smc_call(v8, &v61, qcom_scm_convention, &v58, 0);
LABEL_16:
  v44 = v36;
  result = 0;
  if ( v44 || !v58 )
    goto LABEL_32;
  v72 = 0;
  v74 = 0;
  v70 = 0;
  v71 = 0;
  v60 = 0;
  v61 = 0x100000006LL;
  v73 = 2;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v63 = 0;
  v58 = 0;
  v59 = 0;
  v62 = 1;
  v45 = _get_convention(0, v37, v38, v39, v40, v41, v42, v43);
  if ( (unsigned int)(v45 - 1) >= 3 )
    goto LABEL_21;
  v63 = qword_13660[(unsigned int)(v45 - 1)];
  v52 = _get_convention(v45, v46, v11, v47, v48, v49, v50, v51);
  if ( (unsigned int)(v52 - 2) >= 2 )
  {
    if ( v52 == 1 )
    {
      v54 = scm_legacy_call(v8, (__int64)&v61, &v58);
    }
    else
    {
      printk(&unk_124E9, "qcom_scm_call", v53);
      v54 = -22;
    }
  }
  else
  {
    v54 = _scm_smc_call(v8, &v61, qcom_scm_convention, &v58, 0);
  }
  if ( v54 )
    v57 = 1;
  else
    v57 = v58 == 0;
  result = !v57;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
