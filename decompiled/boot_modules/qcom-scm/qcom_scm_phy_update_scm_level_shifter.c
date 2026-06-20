__int64 __fastcall qcom_scm_phy_update_scm_level_shifter(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 *v8; // x8
  __int64 v9; // x19
  int convention; // w0
  __int64 v11; // x2
  __int64 result; // x0
  __int64 v13; // x2
  unsigned int v14; // w21
  __int64 v15; // [xsp+0h] [xbp-70h] BYREF
  __int64 v16; // [xsp+8h] [xbp-68h]
  __int64 v17; // [xsp+10h] [xbp-60h]
  __int64 v18; // [xsp+18h] [xbp-58h]
  __int64 v19; // [xsp+20h] [xbp-50h]
  __int64 v20; // [xsp+28h] [xbp-48h]
  __int64 v21; // [xsp+30h] [xbp-40h]
  __int64 v22; // [xsp+38h] [xbp-38h]
  __int64 v23; // [xsp+40h] [xbp-30h]
  __int64 v24; // [xsp+48h] [xbp-28h]
  __int64 v25; // [xsp+50h] [xbp-20h]
  __int64 v26; // [xsp+58h] [xbp-18h]
  int v27; // [xsp+60h] [xbp-10h]
  int v28; // [xsp+64h] [xbp-Ch]
  __int64 v29; // [xsp+68h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = (__int64 *)_scm;
  v26 = 0;
  v28 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0x1B00000001LL;
  v27 = 2;
  if ( !_scm )
  {
    v14 = a1;
    result = printk(&unk_12BDA, "qcom_scm_phy_update_scm_level_shifter", a3);
    if ( (_DWORD)result )
      goto LABEL_10;
    v8 = (__int64 *)_scm;
    a1 = v14;
  }
  LODWORD(v16) = 2;
  v17 = (unsigned int)a1;
  v18 = 0;
  v9 = *v8;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call", v11);
      v13 = 4294967274LL;
LABEL_9:
      result = printk(&unk_11F95, "qcom_scm_phy_update_scm_level_shifter", v13);
      goto LABEL_10;
    }
    result = scm_legacy_call(v9, (__int64)&v15, nullptr);
    v13 = (unsigned int)result;
    if ( (_DWORD)result )
      goto LABEL_9;
  }
  else
  {
    result = _scm_smc_call(v9, &v15, qcom_scm_convention, nullptr, 0);
    v13 = (unsigned int)result;
    if ( (_DWORD)result )
      goto LABEL_9;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
