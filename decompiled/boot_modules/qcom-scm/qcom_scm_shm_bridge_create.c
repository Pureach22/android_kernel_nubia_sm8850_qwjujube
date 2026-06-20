__int64 __fastcall qcom_scm_shm_bridge_create(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        _QWORD *a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x20
  int convention; // w0
  __int64 v11; // x2
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-88h] BYREF
  __int64 v14; // [xsp+10h] [xbp-80h]
  __int64 v15; // [xsp+18h] [xbp-78h]
  _QWORD v16[14]; // [xsp+20h] [xbp-70h] BYREF

  v16[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0x1E0000000CLL;
  v16[1] = 4;
  v16[12] = 2;
  v16[2] = a2;
  v16[3] = a3;
  v16[4] = a4;
  v16[5] = a5;
  memset(&v16[6], 0, 48);
  v14 = 0;
  v15 = 0;
  v13 = 0;
  v9 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call", v11);
      result = 4294967274LL;
      goto LABEL_11;
    }
    LODWORD(result) = scm_legacy_call(v9, (__int64)v16, &v13);
    if ( !a6 )
      goto LABEL_8;
  }
  else
  {
    LODWORD(result) = _scm_smc_call(v9, v16, qcom_scm_convention, &v13, 0);
    if ( !a6 )
      goto LABEL_8;
  }
  if ( !(_DWORD)result )
  {
    result = v13;
    *a6 = v14;
    goto LABEL_11;
  }
LABEL_8:
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = v13;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
