__int64 __fastcall gen7_hfi_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  int v4; // w8
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = to_gen7_gmu(a2);
  v6 = 0;
  gmu_core_regread(a2, 129426, &v6);
  gmu_core_regwrite(a2, 129425, 32774);
  v4 = v6;
  if ( (v6 & 4) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, _QWORD))gen7_hfi_process_queue)(v3, 2, 0);
    v4 = v6;
  }
  if ( (v4 & 0x8000) != 0 )
  {
    if ( (unsigned int)__ratelimit(&gen7_hfi_irq_handler__rs, "gen7_hfi_irq_handler") )
      dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "GMU CM3 fault interrupt received\n");
    *(_DWORD *)(v3 + 1084) = 1;
    __dmb(0xAu);
    v4 = v6;
  }
  if ( (v4 & 0xFFFF7FF9) != 0 && (unsigned int)__ratelimit(&gen7_hfi_irq_handler__rs_19, "gen7_hfi_irq_handler") )
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "Unhandled HFI interrupts 0x%lx\n", v6 & 0xFFFF7FF9);
  _ReadStatusReg(SP_EL0);
  return 1;
}
