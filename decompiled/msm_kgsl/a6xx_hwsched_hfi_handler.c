__int64 __fastcall a6xx_hwsched_hfi_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  unsigned int v4; // w8
  int v5; // w9
  unsigned int v13; // w9
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = to_a6xx_gmu(a2);
  v14 = 0;
  gmu_core_regread(a2, 129426, &v14);
  gmu_core_regwrite(a2, 129425, *(_DWORD *)(a2 + 24544) & (unsigned int)v14);
  v4 = v14;
  if ( (*(_BYTE *)(a2 + 24544) & 1) == 0 )
  {
    v4 = v14 & 0xFFFFFFFE;
    v14 &= ~1u;
  }
  if ( (v4 & 5) != 0 )
  {
    _wake_up(a2 + 24584, 1, 1, 0);
    kthread_queue_work(*(_QWORD *)(a2 + 24400), a2 + 24408);
    v4 = v14;
  }
  if ( (v4 & 0x8000) != 0 )
  {
    *(_DWORD *)(v3 + 1280) = 1;
    __dmb(0xAu);
    if ( (unsigned int)__ratelimit(&a6xx_hwsched_hfi_handler__rs, "a6xx_hwsched_hfi_handler") )
      dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "GMU CM3 fault interrupt received\n");
    _X8 = (unsigned int *)(a2 + 24448);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 | 0x20, _X8) );
    __dmb(0xAu);
    kthread_queue_work(*(_QWORD *)(a2 + 24400), a2 + 24408);
    v4 = v14;
  }
  v5 = *(_DWORD *)(a2 + 24544);
  v14 = v4 & 0x1FFFFFF;
  if ( (v4 & 0x1FFFFFF & ~v5) != 0
    && (unsigned int)__ratelimit(&a6xx_hwsched_hfi_handler__rs_62, "a6xx_hwsched_hfi_handler") )
  {
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "Unhandled HFI interrupts 0x%x\n", v14 & ~*(_DWORD *)(a2 + 24544));
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
