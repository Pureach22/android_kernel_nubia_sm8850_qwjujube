__int64 __fastcall msm_cdc_is_ondemand_supply(__int64 a1, __int64 a2, const char **a3, int a4, char *s2)
{
  const char **v6; // x19
  __int64 v7; // x21
  __int64 result; // x0

  if ( !a2 || !s2 )
  {
    result = __ratelimit(&msm_cdc_is_ondemand_supply__rs, "msm_cdc_is_ondemand_supply");
    if ( !(_DWORD)result )
      return result;
    printk(&unk_992E, "msm_cdc_is_ondemand_supply");
    return 0;
  }
  if ( !a1 )
  {
    result = __ratelimit(&msm_cdc_check_supply_param__rs, "msm_cdc_check_supply_param");
    if ( !(_DWORD)result )
      return result;
    printk(&unk_9ED1, "msm_cdc_check_supply_param");
    return 0;
  }
  v6 = a3;
  if ( !a3 || a4 < 1 )
  {
    result = __ratelimit(&msm_cdc_check_supply_param__rs_39, "msm_cdc_check_supply_param");
    if ( !(_DWORD)result )
      return result;
    dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", v6, a4);
    return 0;
  }
  v7 = (unsigned int)a4;
  while ( *((_BYTE *)v6 + 20) != 1 || strcmp(*v6, s2) )
  {
    --v7;
    v6 += 4;
    if ( !v7 )
      return 0;
  }
  return 1;
}
