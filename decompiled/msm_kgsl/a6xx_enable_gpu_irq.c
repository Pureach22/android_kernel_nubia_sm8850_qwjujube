__int64 __fastcall a6xx_enable_gpu_irq(__int64 a1)
{
  kgsl_pwrctrl_irq(a1, 1);
  return adreno_irqctrl(a1, 1);
}
