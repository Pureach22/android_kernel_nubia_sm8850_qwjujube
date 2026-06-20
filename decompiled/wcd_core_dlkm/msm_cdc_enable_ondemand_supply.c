__int64 __fastcall msm_cdc_enable_ondemand_supply(__int64 a1, __int64 a2, char *a3, int a4, char *s2)
{
  __int64 v7; // x22
  _QWORD *v8; // x24
  _BYTE *v9; // x23
  __int64 result; // x0
  unsigned int v11; // w21
  int v12; // w8

  if ( !a2 || !s2 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_enable_ondemand_supply__rs, "msm_cdc_enable_ondemand_supply") )
      printk(&unk_992E, "msm_cdc_enable_ondemand_supply");
    return 4294967274LL;
  }
  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs, "msm_cdc_check_supply_param") )
      printk(&unk_9ED1, "msm_cdc_check_supply_param");
    return 4294967277LL;
  }
  if ( !a3 || a4 < 1 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs_39, "msm_cdc_check_supply_param") )
      dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", a3, a4);
    return 4294967274LL;
  }
  v7 = (unsigned int)a4;
  v8 = (_QWORD *)(a2 + 8);
  v9 = a3 + 23;
  while ( *(v9 - 3) != 1 || strcmp(*(const char **)(v9 - 23), s2) )
  {
    --v7;
    v8 += 3;
    v9 += 32;
    if ( !v7 )
      goto LABEL_14;
  }
  result = regulator_enable(*v8);
  if ( (_DWORD)result )
  {
    v11 = result;
    v12 = __ratelimit(&msm_cdc_enable_ondemand_supply__rs_5, "msm_cdc_enable_ondemand_supply");
    result = v11;
    if ( v12 )
    {
      dev_err(
        a1,
        "%s: failed to enable supply %s, rc: %d\n",
        "msm_cdc_enable_ondemand_supply",
        (const char *)*(v8 - 1),
        v11);
      result = v11;
    }
  }
  *v9 = 1;
  if ( !(_DWORD)v7 )
  {
LABEL_14:
    if ( (unsigned int)__ratelimit(&msm_cdc_enable_ondemand_supply__rs_7, "msm_cdc_enable_ondemand_supply") )
      dev_err(a1, "%s: not able to find supply %s\n", "msm_cdc_enable_ondemand_supply", s2);
    return 4294967274LL;
  }
  return result;
}
