__int64 __fastcall qcom_scm_shm_bridge_enable(
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
  int v29; // w0
  __int64 v30; // x2
  void *v31; // x0
  const char *v32; // x1
  _QWORD v33[3]; // [xsp+8h] [xbp-108h] BYREF
  _QWORD v34[12]; // [xsp+20h] [xbp-F0h] BYREF
  int v35; // [xsp+80h] [xbp-90h]
  int v36; // [xsp+84h] [xbp-8Ch]
  _QWORD v37[3]; // [xsp+88h] [xbp-88h] BYREF
  _QWORD v38[2]; // [xsp+A0h] [xbp-70h] BYREF
  __int64 v39; // [xsp+B0h] [xbp-60h]
  __int64 v40; // [xsp+B8h] [xbp-58h]
  __int64 v41; // [xsp+C0h] [xbp-50h]
  __int64 v42; // [xsp+C8h] [xbp-48h]
  __int64 v43; // [xsp+D0h] [xbp-40h]
  __int64 v44; // [xsp+D8h] [xbp-38h]
  __int64 v45; // [xsp+E0h] [xbp-30h]
  __int64 v46; // [xsp+E8h] [xbp-28h]
  __int64 v47; // [xsp+F0h] [xbp-20h]
  __int64 v48; // [xsp+F8h] [xbp-18h]
  __int64 v49; // [xsp+100h] [xbp-10h]
  __int64 v50; // [xsp+108h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v34[0] = 0x1C0000000CLL;
  memset(&v34[1], 0, 88);
  v35 = 2;
  memset(v33, 0, sizeof(v33));
  v8 = *(_QWORD *)_scm;
  v48 = 0;
  v49 = 2;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38[1] = 1;
  v39 = 0;
  v38[0] = 0x100000006LL;
  memset(v37, 0, sizeof(v37));
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
  {
    v31 = &unk_1227A;
    v32 = "__qcom_scm_is_call_available";
    goto LABEL_18;
  }
  v39 = qword_13738[(unsigned int)(convention - 1)];
  v17 = _get_convention(convention, v10, v11, v12, v13, v14, v15, v16);
  if ( (unsigned int)(v17 - 2) >= 2 )
  {
    if ( v17 == 1 )
    {
      v18 = scm_legacy_call(v8, (__int64)v38, v37);
      goto LABEL_6;
    }
    v31 = &unk_124E9;
    v32 = "qcom_scm_call";
LABEL_18:
    printk(v31, v32, v11);
    result = 4294967201LL;
    goto LABEL_15;
  }
  v18 = _scm_smc_call(v8, v38, qcom_scm_convention, v37, 0);
LABEL_6:
  v26 = v18;
  result = 4294967201LL;
  if ( !v26 && v37[0] )
  {
    v28 = *(_QWORD *)_scm;
    v29 = _get_convention(4294967201LL, v19, v20, v21, v22, v23, v24, v25);
    if ( (unsigned int)(v29 - 2) >= 2 )
    {
      if ( v29 != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v30);
        result = 4294967274LL;
        goto LABEL_15;
      }
      LODWORD(result) = scm_legacy_call(v28, (__int64)v34, v33);
    }
    else
    {
      LODWORD(result) = _scm_smc_call(v28, v34, qcom_scm_convention, v33, 0);
    }
    if ( (_DWORD)result )
      result = (unsigned int)result;
    else
      result = LODWORD(v33[0]);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
