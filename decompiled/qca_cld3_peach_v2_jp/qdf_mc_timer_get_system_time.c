__int64 qdf_mc_timer_get_system_time()
{
  __int64 v1; // [xsp+8h] [xbp-18h] BYREF
  __int64 v2; // [xsp+10h] [xbp-10h]
  __int64 v3; // [xsp+18h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = 0;
  v2 = 0;
  ktime_get_real_ts64(&v1);
  _ReadStatusReg(SP_EL0);
  return v2 / 1000000 + 1000 * v1;
}
