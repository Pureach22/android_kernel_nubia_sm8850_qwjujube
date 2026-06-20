__int64 __fastcall qcom_scm_sec_wdog_trigger(
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
  _QWORD v13[12]; // [xsp+20h] [xbp-70h] BYREF
  int v14; // [xsp+80h] [xbp-10h]
  int v15; // [xsp+84h] [xbp-Ch]
  __int64 v16; // [xsp+88h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v13[2], 0, 80);
  v13[0] = 0x800000001LL;
  v13[1] = 1;
  v15 = 0;
  v14 = 2;
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
    LODWORD(result) = scm_legacy_call(v8, (__int64)v13, v12);
  }
  else
  {
    LODWORD(result) = _scm_smc_call(v8, v13, qcom_scm_convention, v12, 0);
  }
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = LODWORD(v12[0]);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
