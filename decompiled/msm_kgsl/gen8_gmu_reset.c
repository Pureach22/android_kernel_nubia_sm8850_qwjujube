__int64 __fastcall gen8_gmu_reset(_QWORD *a1)
{
  _BYTE *v2; // x20
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  __int64 result; // x0
  unsigned __int64 v13; // x10
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v2 = a1 + 2560;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_irq(a1, 0);
  v14 = 0;
  gmu_core_regread(a1, 129000, &v14);
  if ( (v14 & 3) == 0 )
    adreno_irqctrl((__int64)a1, 0);
  gen8_gmu_irq_disable((__int64)a1);
  gen8_hfi_stop(a1);
  gen8_gmu_suspend((__int64)a1, 1);
  gen8_reset_preempt_records(a1);
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
  _X8 = a1 - 98;
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  result = gen8_boot(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
