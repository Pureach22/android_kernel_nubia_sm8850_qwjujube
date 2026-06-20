__int64 __fastcall _qcom_scm_pas_mss_reset(char a1)
{
  __int64 v1; // x19
  int convention; // w0
  __int64 v3; // x2
  __int64 result; // x0
  _QWORD v5[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v6; // [xsp+20h] [xbp-70h] BYREF
  int v7; // [xsp+28h] [xbp-68h]
  int v8; // [xsp+2Ch] [xbp-64h]
  __int64 v9; // [xsp+30h] [xbp-60h]
  __int64 v10; // [xsp+38h] [xbp-58h]
  __int64 v11; // [xsp+40h] [xbp-50h]
  __int64 v12; // [xsp+48h] [xbp-48h]
  __int64 v13; // [xsp+50h] [xbp-40h]
  __int64 v14; // [xsp+58h] [xbp-38h]
  __int64 v15; // [xsp+60h] [xbp-30h]
  __int64 v16; // [xsp+68h] [xbp-28h]
  __int64 v17; // [xsp+70h] [xbp-20h]
  __int64 v18; // [xsp+78h] [xbp-18h]
  int v19; // [xsp+80h] [xbp-10h]
  int v20; // [xsp+84h] [xbp-Ch]
  __int64 v21; // [xsp+88h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v20 = 0;
  v6 = 0xA00000002LL;
  v8 = 0;
  v7 = 2;
  v19 = 2;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v9 = a1 & 1;
  memset(v5, 0, sizeof(v5));
  v1 = *(_QWORD *)_scm;
  convention = _get_convention();
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call", v3);
      result = 4294967274LL;
      goto LABEL_8;
    }
    LODWORD(result) = scm_legacy_call(v1, (__int64)&v6, v5);
  }
  else
  {
    LODWORD(result) = _scm_smc_call(v1, &v6, qcom_scm_convention, v5, 0);
  }
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = LODWORD(v5[0]);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
