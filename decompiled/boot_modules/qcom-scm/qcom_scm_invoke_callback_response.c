__int64 __fastcall qcom_scm_invoke_callback_response(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        _QWORD *a4,
        _DWORD *a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v11; // x22
  __int64 convention; // x0
  __int64 v13; // x2
  __int64 result; // x0
  __int64 v15; // [xsp+8h] [xbp-88h] BYREF
  __int64 v16; // [xsp+10h] [xbp-80h]
  __int64 v17; // [xsp+18h] [xbp-78h]
  __int64 v18; // [xsp+20h] [xbp-70h] BYREF
  int v19; // [xsp+28h] [xbp-68h]
  int v20; // [xsp+2Ch] [xbp-64h]
  __int64 v21; // [xsp+30h] [xbp-60h]
  __int64 v22; // [xsp+38h] [xbp-58h]
  int v23; // [xsp+40h] [xbp-50h]
  __int64 v24; // [xsp+44h] [xbp-4Ch]
  __int64 v25; // [xsp+4Ch] [xbp-44h]
  __int64 v26; // [xsp+54h] [xbp-3Ch]
  __int64 v27; // [xsp+5Ch] [xbp-34h]
  __int64 v28; // [xsp+64h] [xbp-2Ch]
  __int64 v29; // [xsp+6Ch] [xbp-24h]
  __int64 v30; // [xsp+74h] [xbp-1Ch]
  __int64 v31; // [xsp+7Ch] [xbp-14h]
  char v32; // [xsp+84h] [xbp-Ch]
  __int16 v33; // [xsp+85h] [xbp-Bh]
  char v34; // [xsp+87h] [xbp-9h]
  __int64 v35; // [xsp+88h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v18 = 0x100000006LL;
  v19 = 34;
  v31 = 0x3200000000LL;
  v32 = 1;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v21 = a1;
  v22 = a2;
  v33 = 0;
  v34 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v11 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( (_DWORD)convention == 1 )
    {
      __break(0x800u);
      return qcom_scm_qseecom_call(convention + 184);
    }
    printk(&unk_124E9, "qcom_scm_call_noretry", v13);
    result = 4294967274LL;
    if ( a3 )
      goto LABEL_3;
  }
  else
  {
    result = _scm_smc_call(v11, &v18, qcom_scm_convention, &v15, 2);
    if ( a3 )
LABEL_3:
      *a3 = v16;
  }
  if ( a4 )
    *a4 = v15;
  if ( a5 )
    *a5 = v17;
  _ReadStatusReg(SP_EL0);
  return result;
}
