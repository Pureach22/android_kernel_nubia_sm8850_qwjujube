__int64 __fastcall qcom_scm_qseecom_call(
        __int64 a1,
        int *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w21
  __int64 v10; // x20
  int v11; // w10
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  _QWORD *convention; // x0
  __int64 v19; // x2
  __int64 v20; // x13
  unsigned int v21; // w8
  __int64 result; // x0
  __int64 v23; // x8
  __int64 v24; // x9
  const char *v25; // x1
  __int64 v26; // [xsp+8h] [xbp-88h] BYREF
  __int64 v27; // [xsp+10h] [xbp-80h]
  __int64 v28; // [xsp+18h] [xbp-78h]
  __int64 v29; // [xsp+20h] [xbp-70h] BYREF
  int v30; // [xsp+28h] [xbp-68h]
  int v31; // [xsp+2Ch] [xbp-64h]
  __int64 v32; // [xsp+30h] [xbp-60h]
  __int64 v33; // [xsp+38h] [xbp-58h]
  __int64 v34; // [xsp+40h] [xbp-50h]
  __int64 v35; // [xsp+48h] [xbp-48h]
  __int64 v36; // [xsp+50h] [xbp-40h]
  __int64 v37; // [xsp+58h] [xbp-38h]
  __int64 v38; // [xsp+60h] [xbp-30h]
  __int64 v39; // [xsp+68h] [xbp-28h]
  __int64 v40; // [xsp+70h] [xbp-20h]
  __int64 v41; // [xsp+78h] [xbp-18h]
  unsigned int v42; // [xsp+80h] [xbp-10h]
  int v43; // [xsp+84h] [xbp-Ch]
  __int64 v44; // [xsp+88h] [xbp-8h]

  v8 = a3;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( _scm )
    v10 = *(_QWORD *)_scm;
  else
    v10 = 0;
  v11 = *a2;
  v27 = 0;
  v28 = 0;
  LODWORD(v29) = BYTE1(a1);
  HIDWORD(v29) = (unsigned __int8)a1;
  v12 = *((_QWORD *)a2 + 1);
  v13 = *((_QWORD *)a2 + 2);
  v30 = v11;
  v31 = 0;
  v26 = 0;
  v32 = v12;
  v33 = v13;
  v14 = *((_QWORD *)a2 + 4);
  v34 = *((_QWORD *)a2 + 3);
  v35 = v14;
  v15 = *((_QWORD *)a2 + 6);
  v36 = *((_QWORD *)a2 + 5);
  v37 = v15;
  v16 = *((_QWORD *)a2 + 8);
  v38 = *((_QWORD *)a2 + 7);
  v39 = v16;
  v17 = *((_QWORD *)a2 + 10);
  v40 = *((_QWORD *)a2 + 9);
  v41 = v17;
  v42 = BYTE3(a1) & 0x3F;
  v43 = 0;
  convention = (_QWORD *)_get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  v21 = (_DWORD)convention - 2;
  if ( (v8 & 1) != 0 )
  {
    if ( v21 < 2 )
    {
      result = _scm_smc_call(v10, &v29, qcom_scm_convention, &v26, 0);
LABEL_11:
      v23 = v26;
      v24 = v27;
      *((_QWORD *)a2 + 13) = v28;
      *((_QWORD *)a2 + 11) = v23;
      *((_QWORD *)a2 + 12) = v24;
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( (_DWORD)convention == 1 )
    {
      result = scm_legacy_call(v10, (__int64)&v29, &v26);
      goto LABEL_11;
    }
    v25 = "qcom_scm_call";
LABEL_15:
    printk(&unk_124E9, v25, v19);
    result = 4294967274LL;
    goto LABEL_11;
  }
  if ( v21 < 2 )
  {
    result = _scm_smc_call(v10, &v29, qcom_scm_convention, &v26, 2);
    goto LABEL_11;
  }
  if ( (_DWORD)convention != 1 )
  {
    v25 = "qcom_scm_call_noretry";
    goto LABEL_15;
  }
  __break(0x800u);
  *convention = v20;
  return qcom_scm_gpu_init_regs((char *)convention + 217);
}
