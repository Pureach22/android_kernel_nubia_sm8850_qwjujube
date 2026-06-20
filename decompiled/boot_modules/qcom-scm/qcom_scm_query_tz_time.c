__int64 __fastcall qcom_scm_query_tz_time(
        __int64 *a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v10; // x21
  int convention; // w0
  __int64 v12; // x2
  __int64 result; // x0
  int v14; // w9
  __int64 v15; // [xsp+8h] [xbp-88h] BYREF
  __int64 v16; // [xsp+10h] [xbp-80h]
  __int64 v17; // [xsp+18h] [xbp-78h]
  _QWORD v18[12]; // [xsp+20h] [xbp-70h] BYREF
  int v19; // [xsp+80h] [xbp-10h]
  int v20; // [xsp+84h] [xbp-Ch]
  __int64 v21; // [xsp+88h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v17 = 0;
  v18[0] = 0x1100000001LL;
  v19 = 50;
  memset(&v18[1], 0, 88);
  v15 = 0;
  v16 = 0;
  v10 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call", v12);
      result = 4294967274LL;
      goto LABEL_7;
    }
    result = scm_legacy_call(v10, (__int64)v18, &v15);
    if ( !(_DWORD)result )
      goto LABEL_6;
  }
  else
  {
    result = _scm_smc_call(v10, v18, qcom_scm_convention, &v15, 0);
    if ( !(_DWORD)result )
    {
LABEL_6:
      v14 = v17;
      *a1 = v16 | (v15 << 32);
      *a2 = v14;
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
