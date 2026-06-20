__int64 __fastcall gen8_gmu_wait_for_active_transition(__int64 a1)
{
  int v2; // w8
  __int64 result; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  v2 = gmu_core_timed_poll_check(a1, 129001, 0, 100, 15);
  result = 0;
  if ( v2 )
  {
    gmu_core_regread(a1, 129001, &v4);
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU failed to move to ACTIVE state, Current state: 0x%x\n", v4);
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
