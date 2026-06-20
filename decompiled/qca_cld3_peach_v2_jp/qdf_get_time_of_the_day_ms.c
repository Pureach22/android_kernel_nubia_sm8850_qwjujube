unsigned __int64 qdf_get_time_of_the_day_ms()
{
  __int64 v0; // x8
  int v1; // w10
  __int64 v3; // [xsp+0h] [xbp-40h] BYREF
  __int64 v4; // [xsp+8h] [xbp-38h]
  __int64 v5; // [xsp+10h] [xbp-30h]
  __int64 v6; // [xsp+18h] [xbp-28h]
  int v7; // [xsp+20h] [xbp-20h]
  __int64 v8; // [xsp+28h] [xbp-18h] BYREF
  unsigned __int64 v9; // [xsp+30h] [xbp-10h]
  __int64 v10; // [xsp+38h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v9 = 0;
  v7 = 0;
  v5 = 0;
  v6 = 0;
  v3 = 0;
  v4 = 0;
  ktime_get_real_ts64(&v8);
  rtc_time64_to_tm((unsigned int)(v8 - 60 * sys_tz), &v3);
  v1 = HIDWORD(v3);
  v0 = (int)v4;
  _ReadStatusReg(SP_EL0);
  return (3600000000LL * v0 + 60000000LL * v1 + 1000000LL * (int)v3 + v9 / 0x3E8) / 0x3E8;
}
