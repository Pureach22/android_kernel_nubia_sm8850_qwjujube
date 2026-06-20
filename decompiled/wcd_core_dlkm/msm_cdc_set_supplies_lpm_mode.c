__int64 __fastcall msm_cdc_set_supplies_lpm_mode(__int64 a1, __int64 a2, char *a3, int a4, char a5)
{
  unsigned int v7; // w21
  const char *v8; // x22
  __int64 v9; // x26
  _QWORD *v10; // x27
  unsigned int *v11; // x28
  __int64 v12; // x1

  if ( !a2 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_set_supplies_lpm_mode__rs, "msm_cdc_set_supplies_lpm_mode") )
      printk(&unk_A087, "msm_cdc_set_supplies_lpm_mode");
    return (unsigned int)-22;
  }
  if ( a1 )
  {
    if ( a3 && a4 >= 1 )
    {
      v7 = 0;
      if ( (a5 & 1) != 0 )
        v8 = "LPM";
      else
        v8 = (const char *)&unk_9ECD;
      v9 = (unsigned int)a4;
      v10 = (_QWORD *)(a2 + 8);
      v11 = (unsigned int *)(a3 + 16);
      do
      {
        if ( *((_BYTE *)v11 + 5) == 1 )
        {
          if ( (a5 & 1) != 0 )
            v12 = 0;
          else
            v12 = *v11;
          v7 = regulator_set_load(*v10, v12);
          if ( v7 && (unsigned int)__ratelimit(&msm_cdc_set_supplies_lpm_mode__rs_9, "msm_cdc_set_supplies_lpm_mode") )
            dev_err(
              a1,
              "%s: failed to set supply %s to %s, err:%d\n",
              "msm_cdc_set_supplies_lpm_mode",
              (const char *)*(v10 - 1),
              v8,
              v7);
        }
        --v9;
        v10 += 3;
        v11 += 8;
      }
      while ( v9 );
      return v7;
    }
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs_39, "msm_cdc_check_supply_param") )
      dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", a3, a4);
    return (unsigned int)-22;
  }
  if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs, "msm_cdc_check_supply_param") )
    printk(&unk_9ED1, "msm_cdc_check_supply_param");
  return (unsigned int)-19;
}
