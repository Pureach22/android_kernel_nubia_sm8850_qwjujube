__int64 __fastcall qcom_scm_set_download_mode(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v8; // w20
  __int64 v9; // x19
  __int64 result; // x0
  __int64 convention; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w0
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v28; // x20
  int v29; // w0
  __int64 v30; // x2
  int v31; // w2
  void *v32; // x0
  const char *v33; // x1
  _QWORD v34[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v35; // [xsp+20h] [xbp-70h] BYREF
  __int64 v36; // [xsp+28h] [xbp-68h]
  __int64 v37; // [xsp+30h] [xbp-60h]
  __int64 v38; // [xsp+38h] [xbp-58h]
  __int64 v39; // [xsp+40h] [xbp-50h]
  __int64 v40; // [xsp+48h] [xbp-48h]
  __int64 v41; // [xsp+50h] [xbp-40h]
  __int64 v42; // [xsp+58h] [xbp-38h]
  __int64 v43; // [xsp+60h] [xbp-30h]
  __int64 v44; // [xsp+68h] [xbp-28h]
  __int64 v45; // [xsp+70h] [xbp-20h]
  __int64 v46; // [xsp+78h] [xbp-18h]
  int v47; // [xsp+80h] [xbp-10h]
  int v48; // [xsp+84h] [xbp-Ch]
  __int64 v49; // [xsp+88h] [xbp-8h]

  v8 = a1;
  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( _scm )
  {
    a1 = *(_QWORD *)(_scm + 336);
    v9 = *(_QWORD *)_scm;
    if ( a1 )
    {
      result = qcom_scm_io_writel(a1, v8);
      goto LABEL_16;
    }
  }
  else
  {
    v9 = 0;
  }
  v46 = 0;
  v48 = 0;
  v44 = 0;
  v45 = 0;
  v35 = 0x100000006LL;
  v47 = 2;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v37 = 0;
  memset(v34, 0, sizeof(v34));
  v36 = 1;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
  {
    v32 = &unk_1227A;
    v33 = "__qcom_scm_is_call_available";
LABEL_20:
    printk(v32, v33, v13);
    goto LABEL_21;
  }
  v37 = (__int64)*(&off_13590 + (unsigned int)(convention - 1));
  v19 = _get_convention(convention, v12, v13, v14, v15, v16, v17, v18);
  if ( (unsigned int)(v19 - 2) < 2 )
  {
    v20 = _scm_smc_call(v9, &v35, qcom_scm_convention, v34, 0);
    if ( (_DWORD)v20 )
      goto LABEL_21;
    goto LABEL_11;
  }
  if ( v19 != 1 )
  {
    v32 = &unk_124E9;
    v33 = "qcom_scm_call";
    goto LABEL_20;
  }
  v20 = scm_legacy_call(v9, (__int64)&v35, v34);
  if ( (_DWORD)v20 )
  {
LABEL_21:
    result = dev_err(v9, "No available mechanism for setting download mode\n");
    goto LABEL_17;
  }
LABEL_11:
  if ( !v34[0] )
    goto LABEL_21;
  v46 = 0;
  v48 = 0;
  v35 = 0x1000000001LL;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 2;
  v37 = v8;
  v47 = 2;
  v28 = *(_QWORD *)_scm;
  v29 = _get_convention(v20, v21, v22, v23, v24, v25, v26, v27);
  if ( (unsigned int)(v29 - 2) >= 2 )
  {
    if ( v29 != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call_atomic", v30);
      v31 = -22;
      goto LABEL_23;
    }
    result = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))scm_legacy_call_atomic)(v28, &v35, 0);
  }
  else
  {
    result = _scm_smc_call(v28, &v35, qcom_scm_convention, nullptr, 1);
  }
LABEL_16:
  v31 = result;
  if ( (_DWORD)result )
LABEL_23:
    result = dev_err(v9, "failed to set download mode: %d\n", v31);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
