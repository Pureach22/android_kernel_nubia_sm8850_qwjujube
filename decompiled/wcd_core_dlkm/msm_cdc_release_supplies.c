__int64 __fastcall msm_cdc_release_supplies(__int64 a1, __int64 a2, char *a3, int a4)
{
  __int64 v7; // x24
  _QWORD *v8; // x25
  _BYTE *v9; // x26
  __int64 v10; // x27
  int v11; // w0
  unsigned int *v12; // x19
  _QWORD *v13; // x20

  if ( !a1 || !a2 || !a3 )
  {
    printk(&unk_992E, "msm_cdc_release_supplies");
    return 4294967274LL;
  }
  if ( a4 <= 0 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs_39, "msm_cdc_check_supply_param") )
      dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", a3, a4);
    return 4294967274LL;
  }
  v7 = (unsigned int)a4;
  v8 = (_QWORD *)(a2 + 8);
  v9 = a3 + 23;
  v10 = (unsigned int)a4;
  do
  {
    if ( (*(v9 - 3) & 1) == 0 )
    {
      v11 = regulator_disable(*v8);
      if ( v11 )
        dev_err(
          a1,
          "%s: failed to disable supply %s, err:%d\n",
          "msm_cdc_disable_static_supplies",
          (const char *)*(v8 - 1),
          v11);
      else
        *v9 = 0;
    }
    --v10;
    v8 += 3;
    v9 += 32;
  }
  while ( v10 );
  v12 = (unsigned int *)(a3 + 12);
  v13 = (_QWORD *)(a2 + 8);
  do
  {
    if ( (regulator_count_voltages(*v13) & 0x80000000) == 0 )
    {
      regulator_set_voltage(*v13, 0, *v12);
      regulator_set_load(*v13, 0);
    }
    --v7;
    v12 += 8;
    v13 += 3;
  }
  while ( v7 );
  return 0;
}
