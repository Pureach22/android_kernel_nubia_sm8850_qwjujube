__int64 __fastcall msm_cdc_check_supply_vote(__int64 a1, __int64 a2, const char **a3, int a4, char *s2)
{
  const char **v6; // x19
  __int64 v7; // x21
  char v10; // w8

  if ( !a2 || !s2 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_vote__rs, "msm_cdc_check_supply_vote") )
      printk(&unk_992E, "msm_cdc_check_supply_vote");
    goto LABEL_16;
  }
  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs, "msm_cdc_check_supply_param") )
      printk(&unk_9ED1, "msm_cdc_check_supply_param");
    goto LABEL_16;
  }
  v6 = a3;
  if ( !a3 || a4 < 1 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs_39, "msm_cdc_check_supply_param") )
      dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", v6, a4);
LABEL_16:
    v10 = 0;
    return v10 & 1;
  }
  v7 = (unsigned int)a4;
  while ( strcmp(*v6, s2) )
  {
    --v7;
    v6 += 4;
    if ( !v7 )
      goto LABEL_16;
  }
  v10 = *((_BYTE *)v6 + 23);
  return v10 & 1;
}
