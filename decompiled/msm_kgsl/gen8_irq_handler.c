__int64 __fastcall gen8_irq_handler(_QWORD *a1)
{
  _QWORD *v2; // x24
  __int64 v3; // x22
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x20
  int v6; // w26
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x21
  int v9; // w0
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x22
  int v12; // w23
  unsigned int v13; // w20
  __int64 result; // x0
  unsigned int v15; // w20
  unsigned int v22; // w9

  v2 = a1 + 2560;
  gmu_core_regwrite(a1, 128996, 1);
  v3 = *(_QWORD *)(a1[1783] + 40LL);
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 152);
  if ( *((_DWORD *)v4 - 1) != -944375624 )
    __break(0x8228u);
  v5 = v4(a1);
  if ( (unsigned int)kgsl_regmap_read(a1 + 1650) )
  {
    v6 = 100;
    while ( 1 )
    {
      v7 = *(__int64 (__fastcall **)(_QWORD))(v3 + 152);
      if ( *((_DWORD *)v7 - 1) != -944375624 )
        __break(0x8228u);
      v8 = v7(a1);
      _const_udelay(4295);
      v9 = kgsl_regmap_read(a1 + 1650);
      if ( !v6 )
      {
        if ( v9 )
          break;
      }
      --v6;
      if ( !v9 )
        goto LABEL_14;
    }
    v10 = *(__int64 (__fastcall **)(_QWORD))(v3 + 152);
    if ( *((_DWORD *)v10 - 1) != -944375624 )
      __break(0x8228u);
    v11 = v10(a1);
    v12 = kgsl_regmap_read(a1 + 1650);
    if ( (unsigned int)__ratelimit(&gen8_irq_poll_fence__rs, "gen8_irq_poll_fence") )
      dev_crit(
        *a1,
        "status=0x%x Unmasked status=0x%x Mask=0x%x timestamps: %llx %llx %llx\n",
        v2[51] & v12,
        v12,
        *((_DWORD *)v2 + 102),
        v5,
        v8,
        v11);
    _X8 = (unsigned int *)(a1 + 3056);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 | 0x20, _X8) );
    __dmb(0xAu);
    kthread_queue_work(a1[3050], a1 + 3051);
    result = 0;
  }
  else
  {
LABEL_14:
    v13 = kgsl_regmap_read(a1 + 1650);
    kgsl_regmap_write(a1 + 1650, v13);
    result = adreno_irq_callbacks((__int64)a1, (__int64)&gen8_irq_funcs, v13);
  }
  __dmb(9u);
  if ( (v2[496] & 2) == 0 )
  {
    v15 = result;
    gmu_core_regwrite(a1, 128996, 0);
    return v15;
  }
  return result;
}
