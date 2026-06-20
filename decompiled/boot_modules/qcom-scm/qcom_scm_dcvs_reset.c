__int64 __fastcall qcom_scm_dcvs_reset(
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
  _QWORD v12[12]; // [xsp+0h] [xbp-70h] BYREF
  int v13; // [xsp+60h] [xbp-10h]
  int v14; // [xsp+64h] [xbp-Ch]
  __int64 v15; // [xsp+68h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v12[0] = 0x70000000DLL;
  memset(&v12[1], 0, 88);
  v13 = 2;
  if ( _scm )
    v8 = *(_QWORD *)_scm;
  else
    v8 = 0;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention == 1 )
    {
      result = scm_legacy_call(v8, (__int64)v12, nullptr);
    }
    else
    {
      printk(&unk_124E9, "qcom_scm_call", v10);
      result = 4294967274LL;
    }
  }
  else
  {
    result = _scm_smc_call(v8, v12, qcom_scm_convention, nullptr, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
