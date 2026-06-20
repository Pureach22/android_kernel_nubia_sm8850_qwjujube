__int64 __fastcall gen7_hwsched_hfi_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  unsigned int v4; // w8
  int v5; // w9
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = to_gen7_gmu(a2);
  v7 = 0;
  gmu_core_regread(a2, 129426, &v7);
  gmu_core_regwrite(a2, 129425, *(_DWORD *)(a2 + 24552) & (unsigned int)v7);
  v4 = v7;
  if ( (*(_BYTE *)(a2 + 24552) & 1) == 0 )
  {
    v4 = v7 & 0xFFFFFFFE;
    v7 &= ~1u;
  }
  if ( (v4 & 5) != 0 )
  {
    _wake_up(a2 + 24592, 1, 1, 0);
    kthread_queue_work(*(_QWORD *)(a2 + 24400), a2 + 24408);
    v4 = v7;
  }
  if ( (v4 & 0x8000) != 0 )
  {
    *(_DWORD *)(v3 + 1084) = 1;
    __dmb(0xAu);
    if ( (unsigned int)__ratelimit(&gen7_hwsched_hfi_handler__rs, "gen7_hwsched_hfi_handler") )
      dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "GMU CM3 fault interrupt received\n");
    gen7_hwsched_fault(a2, 32);
    v4 = v7;
  }
  v5 = *(_DWORD *)(a2 + 24552);
  v7 = v4 & 0x1FFFFFF;
  if ( (v4 & 0x1FFFFFF & ~v5) != 0
    && (unsigned int)__ratelimit(&gen7_hwsched_hfi_handler__rs_143, "gen7_hwsched_hfi_handler") )
  {
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "Unhandled HFI interrupts 0x%x\n", v7 & ~*(_DWORD *)(a2 + 24552));
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
