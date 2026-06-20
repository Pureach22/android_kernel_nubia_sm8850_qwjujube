__int64 __fastcall qcom_scm_do_restart(__int64 a1, int a2, char *s1)
{
  unsigned int v4; // w23
  __int64 v7; // x20
  int convention; // w0
  __int64 v9; // x2
  __int64 v10; // x19
  int v11; // w0
  __int64 v12; // x2
  __int64 v14; // [xsp+0h] [xbp-70h] BYREF
  __int64 v15; // [xsp+8h] [xbp-68h]
  __int64 v16; // [xsp+10h] [xbp-60h]
  __int64 v17; // [xsp+18h] [xbp-58h]
  __int64 v18; // [xsp+20h] [xbp-50h]
  __int64 v19; // [xsp+28h] [xbp-48h]
  __int64 v20; // [xsp+30h] [xbp-40h]
  __int64 v21; // [xsp+38h] [xbp-38h]
  __int64 v22; // [xsp+40h] [xbp-30h]
  __int64 v23; // [xsp+48h] [xbp-28h]
  __int64 v24; // [xsp+50h] [xbp-20h]
  __int64 v25; // [xsp+58h] [xbp-18h]
  __int64 v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = qcom_scm_custom_reset_type;
  if ( reboot_mode == 1 && qcom_scm_custom_reset_type == 0 )
  {
    v7 = *(_QWORD *)(a1 - 168);
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v14 = 0x2200000009LL;
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    v26 = 3;
    convention = _get_convention();
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention == 1 )
        ((void (__fastcall *)(__int64, __int64 *, _QWORD))scm_legacy_call_atomic)(v7, &v14, 0);
      else
        printk(&unk_124E9, "qcom_scm_call_atomic", v9);
    }
    else
    {
      _scm_smc_call(v7, &v14, qcom_scm_convention, nullptr, 1);
    }
    v4 = qcom_scm_custom_reset_type;
    goto LABEL_14;
  }
  if ( !s1 )
    goto LABEL_14;
  if ( !strcmp(s1, "rtc") )
  {
    v4 = -2147483643;
    goto LABEL_17;
  }
  if ( strcmp(s1, "twm") )
  {
LABEL_14:
    if ( v4 - 1 >= 0x80000006 )
      goto LABEL_22;
    goto LABEL_18;
  }
  v4 = -2147483642;
LABEL_17:
  qcom_scm_custom_reset_type = v4;
LABEL_18:
  v25 = 0;
  v26 = 0;
  v10 = *(_QWORD *)(a1 - 168);
  v23 = 0;
  v24 = 0;
  v14 = 0x2300000009LL;
  LODWORD(v26) = 3;
  v16 = v4;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 1;
  v11 = _get_convention();
  if ( (unsigned int)(v11 - 2) >= 2 )
  {
    if ( v11 == 1 )
      ((void (__fastcall *)(__int64, __int64 *, _QWORD))scm_legacy_call_atomic)(v10, &v14, 0);
    else
      printk(&unk_124E9, "qcom_scm_call_atomic", v12);
  }
  else
  {
    _scm_smc_call(v10, &v14, qcom_scm_convention, nullptr, 1);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return 1;
}
