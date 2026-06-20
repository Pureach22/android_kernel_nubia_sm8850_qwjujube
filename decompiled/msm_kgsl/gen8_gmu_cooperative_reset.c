__int64 __fastcall gen8_gmu_cooperative_reset(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  gmu_core_regwrite(a1, 129043, 0);
  gmu_core_regwrite(a1, 129428, 0x20000);
  result = gmu_core_timed_poll_check(a1, 129052, 2048, 2, 2048);
  if ( (_DWORD)result )
  {
    gmu_core_regread(a1, 129052, &v3);
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU cooperative reset timed out 0x%x\n", v3);
    gen8_gmu_send_nmi(a1, 1, 0);
    result = gmu_core_regread(a1, 129052, &v3);
    if ( (v3 & 0x800) == 0 )
      result = dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU cooperative reset NMI timed out 0x%x\n", v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
