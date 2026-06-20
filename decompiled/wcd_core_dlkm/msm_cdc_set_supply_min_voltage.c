__int64 __fastcall msm_cdc_set_supply_min_voltage(
        __int64 a1,
        __int64 a2,
        char *a3,
        int a4,
        char *s2,
        unsigned int a6,
        char a7)
{
  __int64 v10; // x23
  unsigned int *v11; // x21
  _QWORD *v12; // x24
  __int64 v17; // x2
  __int64 v18; // x1

  if ( !a2 || !s2 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_set_supply_min_voltage__rs, "msm_cdc_set_supply_min_voltage") )
    {
      printk(&unk_992E, "msm_cdc_set_supply_min_voltage");
      return 4294967274LL;
    }
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
    {
      dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", a3, a4);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v10 = (unsigned int)a4;
  v11 = (unsigned int *)(a3 + 12);
  v12 = (_QWORD *)(a2 + 8);
  while ( strcmp(*(const char **)(v11 - 3), s2) )
  {
    --v10;
    v11 += 8;
    v12 += 3;
    if ( !v10 )
      return 0;
  }
  if ( (a7 & 1) != 0 )
  {
    v17 = *v11;
    v18 = a6;
  }
  else
  {
    v18 = *(v11 - 1);
    v17 = *v11;
  }
  regulator_set_voltage(*v12, v18, v17);
  return 0;
}
