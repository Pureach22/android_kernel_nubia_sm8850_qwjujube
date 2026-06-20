__int64 __fastcall msm_cdc_enable_static_supplies(__int64 a1, __int64 a2, char *a3, int a4)
{
  __int64 v6; // x23
  char *v7; // x24
  __int64 v8; // x21
  int v9; // w0
  __int64 result; // x0
  unsigned int v13; // w25

  if ( !a1 || !a2 || !a3 )
  {
    printk(&unk_992E, "msm_cdc_enable_static_supplies");
    return 4294967274LL;
  }
  if ( a4 < 1 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs_39, "msm_cdc_check_supply_param") )
      dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", a3, a4);
    return 4294967274LL;
  }
  v6 = 0;
  v7 = a3 - 12;
  v8 = 24LL * (unsigned int)a4;
  while ( (v7[32] & 1) != 0 )
  {
LABEL_6:
    v6 += 24;
    v7 += 32;
    if ( v8 == v6 )
      return 0;
  }
  v9 = regulator_enable(*(_QWORD *)(a2 + 8 + v6));
  if ( !v9 )
  {
    v7[35] = 1;
    goto LABEL_6;
  }
  v13 = v9;
  dev_err(
    a1,
    "%s: failed to enable supply %s, rc: %d\n",
    "msm_cdc_enable_static_supplies",
    *(const char **)(a2 + v6),
    v9);
  if ( !v6 )
    return v13;
  result = v13;
  do
  {
    if ( (*v7 & 1) == 0 )
    {
      if ( (unsigned int)regulator_disable(*(_QWORD *)(a2 + v6 - 16)) )
        dev_err(
          a1,
          "%s: failed to disable supply %s during unwind\n",
          "msm_cdc_enable_static_supplies",
          *(const char **)(a2 + v6 - 24));
      else
        v7[3] = 0;
      result = v13;
    }
    v6 -= 24;
    v7 -= 32;
  }
  while ( v6 );
  return result;
}
