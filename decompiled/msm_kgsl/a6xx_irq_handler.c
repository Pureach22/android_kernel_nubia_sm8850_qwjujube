__int64 __fastcall a6xx_irq_handler(__int64 a1)
{
  unsigned __int64 v2; // x20
  int v3; // w22
  unsigned __int64 alwayson; // x21
  int v5; // w0
  unsigned __int64 v6; // x22
  int v7; // w23
  unsigned int v8; // w21
  unsigned int v9; // w20
  unsigned int v17; // w9

  if ( (gmu_core_isenabled(a1) & 1) != 0 )
    gmu_core_regwrite(a1, 129219, 1);
  if ( (gmu_core_isenabled(a1) & 1) != 0 && (v2 = a6xx_read_alwayson(a1), (unsigned int)kgsl_regmap_read(a1 + 13200)) )
  {
    v3 = 100;
    while ( 1 )
    {
      alwayson = a6xx_read_alwayson(a1);
      _const_udelay(4295);
      v5 = kgsl_regmap_read(a1 + 13200);
      if ( !v3 )
      {
        if ( v5 )
          break;
      }
      --v3;
      if ( !v5 )
        goto LABEL_11;
    }
    v6 = a6xx_read_alwayson(a1);
    v7 = kgsl_regmap_read(a1 + 13200);
    if ( (unsigned int)__ratelimit(&a6xx_irq_poll_fence__rs, "a6xx_irq_poll_fence") )
      dev_crit(
        *(_QWORD *)a1,
        "status=0x%x Unmasked status=0x%x Mask=0x%x timestamps: %llx %llx %llx\n",
        *(_DWORD *)(a1 + 20888) & v7,
        v7,
        *(_DWORD *)(a1 + 20888),
        v2,
        alwayson,
        v6);
    _X8 = (unsigned int *)(a1 + 24448);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 | 0x20, _X8) );
    __dmb(0xAu);
    kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
    v9 = 0;
  }
  else
  {
LABEL_11:
    v8 = kgsl_regmap_read(a1 + 13200);
    kgsl_regmap_write(a1 + 13200, v8);
    v9 = adreno_irq_callbacks(a1, (__int64)&a6xx_irq_funcs, v8);
  }
  __dmb(9u);
  if ( (*(_DWORD *)(a1 + 24448) & 2) == 0 && (gmu_core_isenabled(a1) & 1) != 0 )
    gmu_core_regwrite(a1, 129219, 0);
  return v9;
}
