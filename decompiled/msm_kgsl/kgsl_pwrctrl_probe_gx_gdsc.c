__int64 __fastcall kgsl_pwrctrl_probe_gx_gdsc(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x22
  unsigned int v6; // w21
  unsigned __int64 v7; // x0

  if ( of_find_property(*(_QWORD *)(a2 + 760), "power-domains", 0) )
  {
    v4 = dev_pm_domain_attach_by_name(a2 + 16, "gx");
    v5 = v4;
    if ( v4 && v4 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(a1 + 9032) = v4;
      v6 = 0;
      *(_BYTE *)(v4 + 336) |= 2u;
    }
    else
    {
      dev_err_probe(a2 + 16, (unsigned int)v4, "Failed to attach gx power domain\n");
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        return (unsigned int)-22;
      else
        return (unsigned int)v5;
    }
  }
  else
  {
    v7 = devm_regulator_get(a2 + 16, "vdd");
    v6 = v7;
    if ( v7 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(a1 + 9008) = v7;
      return 0;
    }
    else
    {
      dev_err_probe(a2 + 16, (unsigned int)v7, "Couldn't get the vdd\n");
    }
  }
  return v6;
}
