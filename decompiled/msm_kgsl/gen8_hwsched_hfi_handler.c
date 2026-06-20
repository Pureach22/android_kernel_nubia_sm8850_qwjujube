__int64 __fastcall gen8_hwsched_hfi_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x20
  unsigned int v8; // w8
  int v9; // w3
  int v10; // w9
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = to_gen8_gmu(a2);
  v4 = *(_QWORD *)(a2 + 14264);
  v5 = v3;
  v12 = 0;
  v6 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v4 + 40) + 152LL);
  if ( *((_DWORD *)v6 - 1) != -944375624 )
    __break(0x8228u);
  v7 = v6(a2);
  gmu_core_regread(a2, 129426, &v12);
  gmu_core_regwrite(a2, 129425, *(_DWORD *)(a2 + 24616) & (unsigned int)v12);
  v8 = v12;
  if ( (*(_BYTE *)(a2 + 24616) & 1) == 0 )
  {
    v8 = v12 & 0xFFFFFFFE;
    v12 &= ~1u;
  }
  if ( (v8 & 5) != 0 )
  {
    _wake_up(a2 + 24656, 1, 1, 0);
    kthread_queue_work(*(_QWORD *)(a2 + 24400), a2 + 24408);
    v8 = v12;
  }
  if ( (v8 & 0x8000) != 0 )
  {
    *(_DWORD *)(v5 + 1028) = 1;
    __dmb(0xAu);
    if ( (unsigned int)__ratelimit(&gen8_hwsched_hfi_handler__rs, "gen8_hwsched_hfi_handler") )
    {
      dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "GMU CM3 fault interrupt received\n");
      v9 = *(_DWORD *)(a2 + 1536);
      if ( (v9 & 0x20000) == 0 )
        goto LABEL_10;
    }
    else
    {
      v9 = *(_DWORD *)(a2 + 1536);
      if ( (v9 & 0x20000) == 0 )
      {
LABEL_10:
        gen8_hwsched_fault(a2, 32);
        v8 = v12;
        goto LABEL_11;
      }
    }
    dev_err(
      *(_QWORD *)(a2 + 1544) + 16LL,
      "GMU always on ticks: %llx gf_policy: 0x%x gf_trigger: 0x%lx\n",
      v7,
      v9,
      0x20000);
    __break(0x800u);
  }
LABEL_11:
  v10 = *(_DWORD *)(a2 + 24616);
  v12 = v8 & 0x1FFFFFF;
  if ( (v8 & 0x1FFFFFF & ~v10) != 0
    && (unsigned int)__ratelimit(&gen8_hwsched_hfi_handler__rs_166, "gen8_hwsched_hfi_handler") )
  {
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "Unhandled HFI interrupts 0x%x\n", v12 & ~*(_DWORD *)(a2 + 24616));
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
