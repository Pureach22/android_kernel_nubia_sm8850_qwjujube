__int64 __fastcall dsi_ctrl_supplies_deinit(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w22
  __int64 v3; // x0
  const char *v4; // x3
  unsigned int v5; // w22
  __int64 v6; // x0
  const char *v7; // x3

  v1 = result;
  if ( *(_DWORD *)(result + 2408) )
  {
    v2 = 0;
    do
    {
      v3 = *(_QWORD *)(*(_QWORD *)(v1 + 2400) + 80LL * (int)v2);
      if ( v3 )
      {
        result = devm_regulator_put(v3);
      }
      else
      {
        if ( v1 )
          v4 = *(const char **)(v1 + 16);
        else
          v4 = "inv";
        result = drm_dev_printk(
                   0,
                   &unk_248D72,
                   "*ERROR* [msm-dsi-error]: %s: vreg is NULL, should not reach here\n",
                   v4);
      }
      ++v2;
    }
    while ( v2 < *(_DWORD *)(v1 + 2408) );
  }
  if ( *(_DWORD *)(v1 + 2424) )
  {
    v5 = 0;
    do
    {
      v6 = *(_QWORD *)(*(_QWORD *)(v1 + 2416) + 80LL * (int)v5);
      if ( v6 )
      {
        result = devm_regulator_put(v6);
      }
      else
      {
        if ( v1 )
          v7 = *(const char **)(v1 + 16);
        else
          v7 = "inv";
        result = drm_dev_printk(
                   0,
                   &unk_248D72,
                   "*ERROR* [msm-dsi-error]: %s: vreg is NULL, should not reach here\n",
                   v7);
      }
      ++v5;
    }
    while ( v5 < *(_DWORD *)(v1 + 2424) );
  }
  if ( *(_QWORD *)(v1 + 2416) )
  {
    if ( *(_QWORD *)(v1 + 2400) )
      return result;
LABEL_23:
    result = devm_kfree(*(_QWORD *)v1 + 16LL);
    *(_QWORD *)(v1 + 2400) = 0;
    *(_DWORD *)(v1 + 2408) = 0;
    return result;
  }
  result = devm_kfree(*(_QWORD *)v1 + 16LL);
  *(_QWORD *)(v1 + 2416) = 0;
  *(_DWORD *)(v1 + 2424) = 0;
  if ( !*(_QWORD *)(v1 + 2400) )
    goto LABEL_23;
  return result;
}
