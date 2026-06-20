__int64 __fastcall a6xx_gmu_wait_for_active_transition(__int64 a1)
{
  char v2; // w8
  __int64 result; // x0
  int v4; // w8
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v2 = gmu_core_isenabled(a1);
  result = 0;
  if ( (v2 & 1) != 0 )
  {
    v4 = gmu_core_timed_poll_check(a1, 129260, 0, 100, 15);
    result = 0;
    if ( v4 )
    {
      gmu_core_regread(a1, 129260, &v5);
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU failed to move to ACTIVE state, Current state: 0x%x\n", v5);
      result = 4294967186LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
