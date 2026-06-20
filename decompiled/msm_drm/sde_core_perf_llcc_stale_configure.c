__int64 __fastcall sde_core_perf_llcc_stale_configure(__int64 result, __int64 a2)
{
  __int64 v2; // [xsp+8h] [xbp-18h] BYREF
  int v3; // [xsp+10h] [xbp-10h]
  __int64 v4; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  v2 = 0;
  if ( result && a2 && (*(_QWORD *)(result + 22008) & 0x40000000000LL) != 0 )
    result = llcc_configure_staling_mode(a2, &v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
