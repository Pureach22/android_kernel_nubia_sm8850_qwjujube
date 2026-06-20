__int64 __fastcall _get_convention()
{
  __int64 result; // x0
  int v1; // w21
  __int64 v2; // x0
  int v3; // w0
  __int64 v5; // x3
  char *v6; // x2
  __int64 v7; // x21
  _QWORD v8[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v9; // [xsp+20h] [xbp-70h] BYREF
  int v10; // [xsp+28h] [xbp-68h]
  int v11; // [xsp+2Ch] [xbp-64h]
  __int64 v12; // [xsp+30h] [xbp-60h]
  __int64 v13; // [xsp+38h] [xbp-58h]
  __int64 v14; // [xsp+40h] [xbp-50h]
  __int64 v15; // [xsp+48h] [xbp-48h]
  __int64 v16; // [xsp+50h] [xbp-40h]
  __int64 v17; // [xsp+58h] [xbp-38h]
  __int64 v18; // [xsp+60h] [xbp-30h]
  __int64 v19; // [xsp+68h] [xbp-28h]
  __int64 v20; // [xsp+70h] [xbp-20h]
  __int64 v21; // [xsp+78h] [xbp-18h]
  int v22; // [xsp+80h] [xbp-10h]
  int v23; // [xsp+84h] [xbp-Ch]
  __int64 v24; // [xsp+88h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (unsigned int)qcom_scm_convention;
  v21 = 0;
  v23 = 0;
  v9 = 0x100000006LL;
  v11 = 0;
  v10 = 1;
  v19 = 0;
  v20 = 0;
  v12 = 33555969;
  v13 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v22 = 2;
  v14 = 0;
  if ( !qcom_scm_convention )
  {
    memset(v8, 0, sizeof(v8));
    v1 = 3;
    if ( (unsigned int)_scm_smc_call(0, &v9, 3, v8, 1) || v8[0] != 1 )
    {
      v2 = _scm ? *(_QWORD *)(*(_QWORD *)_scm + 744LL) : 0LL;
      if ( !(unsigned int)of_device_is_compatible(v2, "qcom,scm-sc7180") )
      {
        v3 = _scm_smc_call(0, &v9, 2, v8, 1);
        if ( v8[0] == 1 && v3 == 0 )
          v1 = 2;
        else
          v1 = 1;
      }
    }
    v5 = raw_spin_lock_irqsave(&scm_query_lock);
    if ( v1 != qcom_scm_convention )
    {
      qcom_scm_convention = v1;
      v6 = qcom_scm_convention_names[v1];
      v7 = v5;
      printk(&unk_12D30, "__get_convention", v6);
      v5 = v7;
    }
    raw_spin_unlock_irqrestore(&scm_query_lock, v5);
    result = (unsigned int)qcom_scm_convention;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
