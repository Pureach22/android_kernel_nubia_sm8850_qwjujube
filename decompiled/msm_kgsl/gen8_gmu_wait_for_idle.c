__int64 __fastcall gen8_gmu_wait_for_idle(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x22
  __int64 (*v4)(void); // x8
  __int64 v5; // x20
  int v6; // w8
  __int64 result; // x0
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x23
  int v10; // w21
  __int64 v11; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  v12 = 0;
  v3 = *(_QWORD *)(v2 + 40);
  v4 = *(__int64 (**)(void))(v3 + 152);
  if ( *((_DWORD *)v4 - 1) != -944375624 )
    __break(0x8228u);
  v5 = v4();
  v6 = gmu_core_timed_poll_check(a1, 146188, 0, 100, 0x40000000);
  result = 0;
  if ( v6 )
  {
    gmu_core_regread(a1, 146189, &v12);
    v8 = *(__int64 (__fastcall **)(_QWORD))(v3 + 152);
    v9 = *(_QWORD *)(a1 + 1544);
    v10 = v12;
    if ( *((_DWORD *)v8 - 1) != -944375624 )
      __break(0x8228u);
    v11 = v8(a1);
    dev_err(v9 + 16, "GMU not idling: status2=0x%x %llx %llx\n", v10, v5, v11);
    gmu_core_fault_snapshot(a1, 13);
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
