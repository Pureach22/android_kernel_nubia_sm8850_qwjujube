__int64 __fastcall qcom_scm_register_qsee_log_buf(
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
  int convention; // w0
  __int64 v10; // x2
  __int64 result; // x0
  _QWORD v12[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v13; // [xsp+20h] [xbp-70h] BYREF
  int v14; // [xsp+28h] [xbp-68h]
  int v15; // [xsp+2Ch] [xbp-64h]
  __int64 v16; // [xsp+30h] [xbp-60h]
  __int64 v17; // [xsp+38h] [xbp-58h]
  int v18; // [xsp+40h] [xbp-50h]
  __int64 v19; // [xsp+44h] [xbp-4Ch]
  __int64 v20; // [xsp+4Ch] [xbp-44h]
  __int64 v21; // [xsp+54h] [xbp-3Ch]
  __int64 v22; // [xsp+5Ch] [xbp-34h]
  __int64 v23; // [xsp+64h] [xbp-2Ch]
  __int64 v24; // [xsp+6Ch] [xbp-24h]
  __int64 v25; // [xsp+74h] [xbp-1Ch]
  int v26; // [xsp+7Ch] [xbp-14h]
  __int64 v27; // [xsp+80h] [xbp-10h]
  __int64 v28; // [xsp+88h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v13 = 0x600000001LL;
  v14 = 34;
  v27 = 50;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v16 = a1;
  v17 = a2;
  memset(v12, 0, sizeof(v12));
  v8 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call", v10);
      result = 4294967274LL;
      goto LABEL_8;
    }
    LODWORD(result) = scm_legacy_call(v8, (__int64)&v13, v12);
  }
  else
  {
    LODWORD(result) = _scm_smc_call(v8, &v13, qcom_scm_convention, v12, 0);
  }
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = LODWORD(v12[0]);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
