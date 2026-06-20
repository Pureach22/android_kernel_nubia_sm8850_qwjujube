__int64 __fastcall msm_cdc_disable_static_supplies(__int64 a1, __int64 a2, char *a3, int a4)
{
  __int64 result; // x0
  __int64 v6; // x23
  _QWORD *v7; // x24
  _BYTE *v8; // x25
  unsigned int v9; // w22

  if ( !a1 || !a2 || !a3 )
  {
    printk(&unk_992E, "msm_cdc_disable_static_supplies");
    return 4294967274LL;
  }
  if ( a4 < 1 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_check_supply_param__rs_39, "msm_cdc_check_supply_param") )
      dev_err(a1, "%s: supply check failed: vreg: %pK, num_supplies: %d\n", "msm_cdc_check_supply_param", a3, a4);
    return 4294967274LL;
  }
  result = 0;
  v6 = (unsigned int)a4;
  v7 = (_QWORD *)(a2 + 8);
  v8 = a3 + 23;
  do
  {
    if ( (*(v8 - 3) & 1) == 0 )
    {
      result = regulator_disable(*v7);
      if ( (_DWORD)result )
      {
        v9 = result;
        dev_err(
          a1,
          "%s: failed to disable supply %s, err:%d\n",
          "msm_cdc_disable_static_supplies",
          (const char *)*(v7 - 1),
          result);
        result = v9;
      }
      else
      {
        *v8 = 0;
      }
    }
    --v6;
    v7 += 3;
    v8 += 32;
  }
  while ( v6 );
  return result;
}
