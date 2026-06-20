__int64 __fastcall gen7_gmu_device_start(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x20
  void (__fastcall *v9)(_QWORD); // x8
  int v10; // w8
  __int64 result; // x0

  gmu_core_reset_trace_header(a1 + 8672);
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v9 = *(void (__fastcall **)(_QWORD))(v2 + 152);
  if ( *((_DWORD *)v9 - 1) != -944375624 )
    __break(0x8228u);
  v9(a1);
  _WriteStatusReg(DAIF, StatusReg);
  gmu_core_regwrite(a1, 129024, 0);
  __dsb(0xEu);
  v10 = gmu_core_timed_poll_check(a1, 129052, 256, 100, 511);
  result = 0;
  if ( v10 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU failed to come out of reset\n");
    gmu_core_fault_snapshot(a1, 1);
    return 4294967186LL;
  }
  return result;
}
