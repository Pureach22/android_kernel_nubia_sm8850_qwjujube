__int64 __fastcall a6xx_rgmu_reset(_QWORD *a1)
{
  _BYTE *v2; // x20
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v13; // x10

  v2 = a1 + 2560;
  a6xx_disable_gpu_irq((__int64)a1);
  disable_irq(*((unsigned int *)a1 - 20));
  disable_irq(*((unsigned int *)a1 - 19));
  gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
  a6xx_rgmu_disable_clks(a1);
  kgsl_pwrctrl_disable_cx_gdsc(a1);
  kgsl_pwrctrl_set_state(a1, 0);
  a6xx_reset_preempt_records((__int64)a1);
  if ( v2[352] == 1 )
  {
    v3 = a1[2603];
    if ( v3 )
    {
      if ( v3 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( v2[368] == 1 )
  {
    v4 = a1[2605];
    if ( v4 )
    {
      if ( v4 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( v2[384] == 1 )
  {
    v5 = a1[2607];
    if ( v5 )
    {
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  _X8 = a1 - 2;
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  return a6xx_boot_0(a1);
}
