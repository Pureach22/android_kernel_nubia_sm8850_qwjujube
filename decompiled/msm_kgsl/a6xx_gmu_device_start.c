__int64 __fastcall a6xx_gmu_device_start(__int64 a1)
{
  unsigned __int64 StatusReg; // x20
  unsigned int v8; // w21
  unsigned int v9; // w20
  int v10; // w8
  __int64 result; // x0

  gmu_core_reset_trace_header(a1 + 8672);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  a6xx_read_alwayson(a1);
  _WriteStatusReg(DAIF, StatusReg);
  if ( *(_DWORD *)(a1 + 8264) < 0x20010005u )
    v8 = -1;
  else
    v8 = 511;
  if ( *(_DWORD *)(a1 + 8264) >= 0x20010005u )
    v9 = 256;
  else
    v9 = -1161889074;
  gmu_core_regwrite(a1, 129024, 0);
  __dsb(0xEu);
  v10 = gmu_core_timed_poll_check(a1, 129052, v9, 100, v8);
  result = 0;
  if ( v10 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU doesn't boot\n");
    gmu_core_fault_snapshot(a1, 1);
    return 4294967186LL;
  }
  return result;
}
