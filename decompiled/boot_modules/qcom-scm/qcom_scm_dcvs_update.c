__int64 __fastcall qcom_scm_dcvs_update(
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
  _QWORD v13[14]; // [xsp+20h] [xbp-70h] BYREF

  v13[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0x80000000DLL;
  v13[1] = 3;
  v13[12] = 2;
  v13[2] = (int)a1;
  v13[3] = a2;
  v13[4] = a3;
  memset(&v13[5], 0, 56);
  memset(v12, 0, sizeof(v12));
  v8 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call_atomic", v10);
      result = 4294967274LL;
      goto LABEL_8;
    }
    LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD *))scm_legacy_call_atomic)(v8, v13, v12);
  }
  else
  {
    LODWORD(result) = _scm_smc_call(v8, v13, qcom_scm_convention, v12, 1);
  }
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = LODWORD(v12[0]);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
