__int64 __fastcall qcom_scm_pas_supported(
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
  int v31; // w0
  bool v32; // zf
  void *v33; // x0
  const char *v34; // x1
  _QWORD v35[3]; // [xsp+8h] [xbp-108h] BYREF
  _QWORD v36[12]; // [xsp+20h] [xbp-F0h] BYREF
  int v37; // [xsp+80h] [xbp-90h]
  int v38; // [xsp+84h] [xbp-8Ch]
  _QWORD v39[3]; // [xsp+88h] [xbp-88h] BYREF
  _QWORD v40[2]; // [xsp+A0h] [xbp-70h] BYREF
  __int64 v41; // [xsp+B0h] [xbp-60h]
  __int64 v42; // [xsp+B8h] [xbp-58h]
  __int64 v43; // [xsp+C0h] [xbp-50h]
  __int64 v44; // [xsp+C8h] [xbp-48h]
  __int64 v45; // [xsp+D0h] [xbp-40h]
  __int64 v46; // [xsp+D8h] [xbp-38h]
  __int64 v47; // [xsp+E0h] [xbp-30h]
  __int64 v48; // [xsp+E8h] [xbp-28h]
  __int64 v49; // [xsp+F0h] [xbp-20h]
  __int64 v50; // [xsp+F8h] [xbp-18h]
  __int64 v51; // [xsp+100h] [xbp-10h]
  __int64 v52; // [xsp+108h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36[2] = (unsigned int)a1;
  v36[0] = 0x700000002LL;
  v36[1] = 1;
  v38 = 0;
  memset(&v36[3], 0, 72);
  v37 = 2;
  memset(v35, 0, sizeof(v35));
  v8 = *(_QWORD *)_scm;
  v50 = 0;
  v51 = 2;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40[1] = 1;
  v41 = 0;
  v40[0] = 0x100000006LL;
  memset(v39, 0, sizeof(v39));
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 1) >= 3 )
  {
    v33 = &unk_1227A;
    v34 = "__qcom_scm_is_call_available";
    goto LABEL_21;
  }
  v41 = (__int64)*(&off_135A8 + (unsigned int)(convention - 1));
  v17 = _get_convention(convention, v10, v11, v12, v13, v14, v15, v16);
  if ( (unsigned int)(v17 - 2) >= 2 )
  {
    if ( v17 == 1 )
    {
      v18 = scm_legacy_call(v8, (__int64)v40, v39);
      goto LABEL_6;
    }
    v33 = &unk_124E9;
    v34 = "qcom_scm_call";
LABEL_21:
    printk(v33, v34, v11);
    result = 0;
    goto LABEL_18;
  }
  v18 = _scm_smc_call(v8, v40, qcom_scm_convention, v39, 0);
LABEL_6:
  v26 = v18;
  result = 0;
  if ( !v26 && v39[0] )
  {
    v28 = *(_QWORD *)_scm;
    v29 = _get_convention(0, v19, v20, v21, v22, v23, v24, v25);
    if ( (unsigned int)(v29 - 2) >= 2 )
    {
      if ( v29 == 1 )
      {
        v31 = scm_legacy_call(v28, (__int64)v36, v35);
      }
      else
      {
        printk(&unk_124E9, "qcom_scm_call", v30);
        v31 = -22;
      }
    }
    else
    {
      v31 = _scm_smc_call(v28, v36, qcom_scm_convention, v35, 0);
    }
    if ( v31 )
      v32 = 1;
    else
      v32 = v35[0] == 0;
    result = !v32;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
