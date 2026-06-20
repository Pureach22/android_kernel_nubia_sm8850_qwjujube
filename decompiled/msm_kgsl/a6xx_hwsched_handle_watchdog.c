__int64 __fastcall a6xx_hwsched_handle_watchdog(__int64 a1)
{
  __int64 result; // x0
  unsigned int v9; // w9
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  gmu_core_regread(a1, 146182, &v10);
  gmu_core_regwrite(a1, 146182, v10 | 1u);
  a6xx_gmu_send_nmi(a1, 0, 0);
  if ( (unsigned int)__ratelimit(&a6xx_hwsched_handle_watchdog__rs, "a6xx_hwsched_handle_watchdog") )
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU watchdog expired interrupt received\n");
  _X8 = (unsigned int *)(a1 + 24448);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 | 0x20, _X8) );
  __dmb(0xAu);
  result = kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
  _ReadStatusReg(SP_EL0);
  return result;
}
