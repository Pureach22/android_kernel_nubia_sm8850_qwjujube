__int64 __fastcall a6xx_rgmu_irq_handler(__int64 a1, __int64 a2)
{
  unsigned int v3; // w8
  int v5; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  gmu_core_regread(a2, 146181, &v6);
  v3 = v6;
  if ( (v6 & 8) != 0 )
  {
    v5 = 0;
    gmu_core_regread(a2, 146195, &v5);
    gmu_core_regwrite(a2, 146180, v6);
    if ( (unsigned int)__ratelimit(&a6xx_rgmu_irq_handler__rs, "a6xx_rgmu_irq_handler") )
      dev_err(*(_QWORD *)(a2 - 88) + 16LL, "FENCE error interrupt received %x\n", v5);
    v3 = v6;
  }
  if ( (v3 & 0xFFFFFFF7) != 0 && (unsigned int)__ratelimit(&a6xx_rgmu_irq_handler__rs_36, "a6xx_rgmu_irq_handler") )
    dev_err(*(_QWORD *)(a2 - 88) + 16LL, "Unhandled RGMU interrupts 0x%lx\n", v6 & 0xFFFFFFF7);
  _ReadStatusReg(SP_EL0);
  return 1;
}
