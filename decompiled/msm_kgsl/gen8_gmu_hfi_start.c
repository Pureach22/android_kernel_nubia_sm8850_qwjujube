__int64 __fastcall gen8_gmu_hfi_start(__int64 a1)
{
  __int64 result; // x0

  gmu_core_regwrite(a1, 129414, 1);
  result = gmu_core_timed_poll_check(a1, 129408, 1, 100, 1);
  if ( (_DWORD)result )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU HFI init failed\n");
    gmu_core_fault_snapshot(a1, 2);
    return 4294967186LL;
  }
  return result;
}
