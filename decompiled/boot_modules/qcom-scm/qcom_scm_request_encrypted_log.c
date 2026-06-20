__int64 __fastcall qcom_scm_request_encrypted_log(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v8; // w8
  __int64 v9; // x19
  int convention; // w0
  __int64 v11; // x2
  __int64 result; // x0
  _QWORD v13[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v14[5]; // [xsp+20h] [xbp-70h] BYREF
  __int64 v15; // [xsp+48h] [xbp-48h]
  __int64 v16; // [xsp+50h] [xbp-40h]
  __int64 v17; // [xsp+58h] [xbp-38h]
  __int64 v18; // [xsp+60h] [xbp-30h]
  __int64 v19; // [xsp+68h] [xbp-28h]
  __int64 v20; // [xsp+70h] [xbp-20h]
  __int64 v21; // [xsp+78h] [xbp-18h]
  __int64 v22; // [xsp+80h] [xbp-10h]
  __int64 v23; // [xsp+88h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[2] = a1;
  v14[3] = a2;
  v14[0] = 0xC00000001LL;
  v14[4] = (unsigned int)a3;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 50;
  if ( (a4 & 1) != 0 )
  {
    v15 = a5 & 1;
    v8 = 36;
  }
  else
  {
    v8 = 35;
  }
  memset(v13, 0, sizeof(v13));
  v14[1] = v8;
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
    LODWORD(result) = scm_legacy_call(v9, (__int64)v14, v13);
  }
  else
  {
    LODWORD(result) = _scm_smc_call(v9, v14, qcom_scm_convention, v13, 0);
  }
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = LODWORD(v13[0]);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
