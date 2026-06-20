__int64 __fastcall a6xx_gmu_wait_for_idle(__int64 a1)
{
  unsigned __int64 alwayson; // x20
  int v3; // w8
  __int64 result; // x0
  __int64 v5; // x22
  int v6; // w21
  unsigned __int64 v7; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  alwayson = a6xx_read_alwayson(a1);
  v3 = gmu_core_timed_poll_check(a1, 146188, 0, 100, 0x40000000);
  result = 0;
  if ( v3 )
  {
    gmu_core_regread(a1, 146189, &v8);
    v5 = *(_QWORD *)(a1 + 1544);
    v6 = v8;
    v7 = a6xx_read_alwayson(a1);
    dev_err(v5 + 16, "GMU not idling: status2=0x%x %llx %llx\n", v6, alwayson, v7);
    gmu_core_fault_snapshot(a1, 13);
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
