__int64 __fastcall qcom_scm_invoke_smc_legacy(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _DWORD *a5,
        _QWORD *a6,
        _DWORD *a7,
        __int64 a8)
{
  __int64 v11; // x22
  int convention; // w0
  __int64 v13; // x2
  __int64 result; // x0
  __int64 v15; // [xsp+8h] [xbp-88h] BYREF
  __int64 v16; // [xsp+10h] [xbp-80h]
  __int64 v17; // [xsp+18h] [xbp-78h]
  _QWORD v18[12]; // [xsp+20h] [xbp-70h] BYREF
  int v19; // [xsp+80h] [xbp-10h]
  char v20; // [xsp+84h] [xbp-Ch]
  __int16 v21; // [xsp+85h] [xbp-Bh]
  char v22; // [xsp+87h] [xbp-9h]
  __int64 v23; // [xsp+88h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 6;
  v18[1] = 548;
  v19 = 50;
  v20 = 1;
  v18[2] = a1;
  v18[3] = a2;
  v18[4] = a3;
  v18[5] = a4;
  memset(&v18[6], 0, 48);
  v21 = 0;
  v22 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v11 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention == 1 )
    {
      __break(0x800u);
      return qcom_scm_invoke_smc();
    }
    printk(&unk_124E9, "qcom_scm_call_noretry", v13);
    result = 4294967274LL;
    if ( a5 )
      goto LABEL_3;
  }
  else
  {
    result = _scm_smc_call(v11, v18, qcom_scm_convention, &v15, 2);
    if ( a5 )
LABEL_3:
      *a5 = v16;
  }
  if ( a6 )
    *a6 = v15;
  if ( a7 )
    *a7 = v17;
  _ReadStatusReg(SP_EL0);
  return result;
}
