__int64 __fastcall a6xx_oob_irq_handler(__int64 a1, __int64 a2)
{
  unsigned int v3; // w2
  unsigned int v11; // w9
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  gmu_core_regread(a2, 129426, &v12);
  v3 = v12;
  if ( (v12 & 0x1000000) != 0 )
  {
    gmu_core_regwrite(a2, 129425, v12);
    if ( (unsigned int)__ratelimit(&a6xx_oob_irq_handler__rs, "a6xx_oob_irq_handler") )
      dev_err(*(_QWORD *)(a2 - 88) + 16LL, "RGMU oob irq error\n");
    _X8 = (unsigned int *)(a2 + 24448);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 | 0x20, _X8) );
    __dmb(0xAu);
    kthread_queue_work(*(_QWORD *)(a2 + 24400), a2 + 24408);
    v3 = v12;
  }
  if ( (v3 & 0xFFFFFF) != 0 && (unsigned int)__ratelimit(&a6xx_oob_irq_handler__rs_33, "a6xx_oob_irq_handler") )
    dev_err(*(_QWORD *)(a2 - 88) + 16LL, "Unhandled OOB interrupts 0x%lx\n", v12 & 0xFFFFFFLL);
  _ReadStatusReg(SP_EL0);
  return 1;
}
