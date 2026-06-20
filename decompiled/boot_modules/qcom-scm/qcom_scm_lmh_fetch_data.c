__int64 __fastcall qcom_scm_lmh_fetch_data(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        _DWORD *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v10; // x21
  __int64 convention; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w0
  int v20; // w0
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  int v28; // w8
  __int64 result; // x0
  __int64 v30; // x21
  int v31; // w0
  __int64 v32; // x2
  void *v33; // x0
  const char *v34; // x1
  __int64 v35; // [xsp+8h] [xbp-108h] BYREF
  __int64 v36; // [xsp+10h] [xbp-100h]
  __int64 v37; // [xsp+18h] [xbp-F8h]
  __int64 v38; // [xsp+20h] [xbp-F0h] BYREF
  int v39; // [xsp+28h] [xbp-E8h]
  int v40; // [xsp+2Ch] [xbp-E4h]
  __int64 v41; // [xsp+30h] [xbp-E0h]
  __int64 v42; // [xsp+38h] [xbp-D8h]
  int v43; // [xsp+40h] [xbp-D0h]
  __int64 v44; // [xsp+44h] [xbp-CCh]
  __int64 v45; // [xsp+4Ch] [xbp-C4h]
  __int64 v46; // [xsp+54h] [xbp-BCh]
  __int64 v47; // [xsp+5Ch] [xbp-B4h]
  __int64 v48; // [xsp+64h] [xbp-ACh]
  __int64 v49; // [xsp+6Ch] [xbp-A4h]
  __int64 v50; // [xsp+74h] [xbp-9Ch]
  int v51; // [xsp+7Ch] [xbp-94h]
  __int64 v52; // [xsp+80h] [xbp-90h]
  _QWORD v53[3]; // [xsp+88h] [xbp-88h] BYREF
  _QWORD v54[2]; // [xsp+A0h] [xbp-70h] BYREF
  __int64 v55; // [xsp+B0h] [xbp-60h]
  __int64 v56; // [xsp+B8h] [xbp-58h]
  __int64 v57; // [xsp+C0h] [xbp-50h]
  __int64 v58; // [xsp+C8h] [xbp-48h]
  __int64 v59; // [xsp+D0h] [xbp-40h]
  __int64 v60; // [xsp+D8h] [xbp-38h]
  __int64 v61; // [xsp+E0h] [xbp-30h]
  __int64 v62; // [xsp+E8h] [xbp-28h]
  __int64 v63; // [xsp+F0h] [xbp-20h]
  __int64 v64; // [xsp+F8h] [xbp-18h]
  __int64 v65; // [xsp+100h] [xbp-10h]
  __int64 v66; // [xsp+108h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = 0xD00000013LL;
  v40 = 0;
  v43 = 0;
  v41 = (unsigned int)a1;
  v42 = (unsigned int)a2;
  v39 = 2;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 2;
  v35 = 0;
  v36 = 0;
  v10 = *(_QWORD *)_scm;
  v64 = 0;
  v65 = 2;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54[1] = 1;
  v55 = 0;
  v54[0] = 0x100000006LL;
  memset(v53, 0, sizeof(v53));
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
  {
    v33 = &unk_1227A;
    v34 = "__qcom_scm_is_call_available";
    goto LABEL_18;
  }
  v55 = qword_13708[(unsigned int)(convention - 1)];
  v19 = _get_convention(convention, v12, v13, v14, v15, v16, v17, v18);
  if ( (unsigned int)(v19 - 2) >= 2 )
  {
    if ( v19 == 1 )
    {
      v20 = scm_legacy_call(v10, (__int64)v54, v53);
      goto LABEL_6;
    }
    v33 = &unk_124E9;
    v34 = "qcom_scm_call";
LABEL_18:
    printk(v33, v34, v13);
    result = 0;
    goto LABEL_19;
  }
  v20 = _scm_smc_call(v10, v54, qcom_scm_convention, v53, 0);
LABEL_6:
  v28 = v20;
  result = 0;
  if ( v28 || !v53[0] )
    goto LABEL_19;
  v30 = *(_QWORD *)_scm;
  v31 = _get_convention(0, v21, v22, v23, v24, v25, v26, v27);
  if ( (unsigned int)(v31 - 2) < 2 )
  {
    result = _scm_smc_call(v30, &v38, qcom_scm_convention, &v35, 0);
    if ( !a3 )
      goto LABEL_14;
    goto LABEL_13;
  }
  if ( v31 == 1 )
  {
    result = scm_legacy_call(v30, (__int64)&v38, &v35);
    if ( !a3 )
      goto LABEL_14;
    goto LABEL_13;
  }
  printk(&unk_124E9, "qcom_scm_call", v32);
  result = 4294967274LL;
  if ( a3 )
LABEL_13:
    *a3 = v35;
LABEL_14:
  if ( a4 )
    *a4 = v36;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
