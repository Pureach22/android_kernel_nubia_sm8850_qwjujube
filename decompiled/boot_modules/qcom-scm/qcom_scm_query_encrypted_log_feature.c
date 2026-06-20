__int64 __fastcall qcom_scm_query_encrypted_log_feature(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x20
  int convention; // w0
  __int64 v11; // x2
  __int64 result; // x0
  _QWORD v13[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v14[12]; // [xsp+20h] [xbp-70h] BYREF
  int v15; // [xsp+80h] [xbp-10h]
  int v16; // [xsp+84h] [xbp-Ch]
  __int64 v17; // [xsp+88h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v14[0] = 0xB00000001LL;
  v15 = 50;
  memset(&v14[1], 0, 88);
  memset(v13, 0, sizeof(v13));
  v9 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call", v11);
      result = 4294967274LL;
      goto LABEL_7;
    }
    result = scm_legacy_call(v9, (__int64)v14, v13);
    if ( !(_DWORD)result )
      goto LABEL_6;
  }
  else
  {
    result = _scm_smc_call(v9, v14, qcom_scm_convention, v13, 0);
    if ( !(_DWORD)result )
LABEL_6:
      *a1 = v13[0];
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
