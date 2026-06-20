__int64 __fastcall kgsl_pwrctrl_probe_cx_gdsc(_QWORD *a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x0
  unsigned int v7; // w22
  unsigned __int64 v8; // x0

  if ( !of_find_property(*(_QWORD *)(a2 + 760), "power-domains", 0) )
  {
    v8 = devm_regulator_get(a2 + 16, "vddcx");
    v7 = v8;
    if ( v8 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err_probe(a2 + 16, (unsigned int)v8, "Couldn't get the vddcx\n");
      return v7;
    }
    a1[1125] = v8;
    return 0;
  }
  v4 = dev_pm_domain_attach_by_name(a2 + 16, "cx");
  v5 = v4;
  if ( v4 && v4 < 0xFFFFFFFFFFFFF001LL )
  {
    a1[1127] = v4;
    v6 = dev_pm_domain_attach_by_name(a2 + 16, "gmu_cx");
    a1[1128] = v6;
    if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(*a1, "Failed to attach GMU cx power domain, falling back to cx pd\n");
      v7 = 0;
      a1[1128] = v5;
      return v7;
    }
    return 0;
  }
  dev_err_probe(a2 + 16, (unsigned int)v4, "Failed to attach cx power domain\n");
  if ( v5 <= 0xFFFFFFFFFFFFF000LL )
    return (unsigned int)-22;
  else
    return (unsigned int)v5;
}
