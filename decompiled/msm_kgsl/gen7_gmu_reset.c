__int64 __fastcall gen7_gmu_reset(_QWORD *a1)
{
  _BYTE *v2; // x20
  unsigned int *v3; // x22
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  __int64 result; // x0
  unsigned __int64 v14; // x10
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v2 = a1 + 2560;
  v3 = (unsigned int *)(a1 - 222);
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_irq(a1, 0);
  v15 = 0;
  gmu_core_regread(a1, 129232, &v15);
  if ( (v15 & 3) == 0 )
    adreno_irqctrl((__int64)a1, 0);
  disable_irq(*v3);
  disable_irq(*((unsigned int *)a1 - 434));
  gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
  gen7_hfi_stop(a1);
  gen7_gmu_suspend((__int64)a1, 1);
  gen7_reset_preempt_records(a1);
  if ( v2[352] == 1 )
  {
    v4 = a1[2603];
    if ( v4 )
    {
      if ( v4 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( v2[368] == 1 )
  {
    v5 = a1[2605];
    if ( v5 )
    {
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( v2[384] == 1 )
  {
    v6 = a1[2607];
    if ( v6 )
    {
      if ( v6 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  _X8 = a1 - 85;
  __asm { PRFM            #0x11, [X8] }
  do
    v14 = __ldxr(_X8);
  while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  result = gen7_boot(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
