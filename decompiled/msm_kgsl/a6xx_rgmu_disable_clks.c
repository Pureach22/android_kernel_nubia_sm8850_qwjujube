__int64 __fastcall a6xx_rgmu_disable_clks(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v3; // x19

  if ( a6xx_rgmu_gx_is_on(a1) )
  {
    kgsl_pwrctrl_enable_gx_gdsc(a1);
    kgsl_pwrctrl_disable_gx_gdsc(a1);
    if ( a6xx_rgmu_gx_is_on(a1) )
      dev_err(*(_QWORD *)(a1 - 88) + 16LL, "gx is stuck on\n");
  }
  v2 = *(_DWORD *)(a1 - 48);
  v3 = *(_QWORD *)(a1 - 56);
  clk_bulk_disable(v2, v3);
  return clk_bulk_unprepare(v2, v3);
}
