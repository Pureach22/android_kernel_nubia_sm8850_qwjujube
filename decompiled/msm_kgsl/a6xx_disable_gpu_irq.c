__int64 __fastcall a6xx_disable_gpu_irq(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_irq(a1, 0);
  v3 = 0;
  result = gmu_core_regread(a1, 129232, &v3);
  if ( (v3 & 0xC0) == 0 )
    result = adreno_irqctrl(a1, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
