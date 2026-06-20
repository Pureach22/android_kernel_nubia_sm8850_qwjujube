__int64 __fastcall gen7_gmu_handle_watchdog(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  gmu_core_regread(a1, 146182, &v3);
  gmu_core_regwrite(a1, 146182, v3 | 1u);
  gen7_gmu_send_nmi(a1, 0, 0);
  result = __ratelimit(&gen7_gmu_handle_watchdog__rs, "gen7_gmu_handle_watchdog");
  if ( (_DWORD)result )
    result = dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU watchdog expired interrupt received\n");
  _ReadStatusReg(SP_EL0);
  return result;
}
