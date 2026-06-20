__int64 __fastcall qdf_get_time_of_the_day_in_hr_min_sec_usec(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // [xsp+0h] [xbp-40h] BYREF
  __int64 v6; // [xsp+8h] [xbp-38h]
  __int64 v7; // [xsp+10h] [xbp-30h]
  __int64 v8; // [xsp+18h] [xbp-28h]
  int v9; // [xsp+20h] [xbp-20h]
  __int64 v10; // [xsp+28h] [xbp-18h] BYREF
  __int64 v11; // [xsp+30h] [xbp-10h]
  __int64 v12; // [xsp+38h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11 = 0;
  v9 = 0;
  v7 = 0;
  v8 = 0;
  v5 = 0;
  v6 = 0;
  ktime_get_real_ts64(&v10);
  rtc_time64_to_tm((unsigned int)(v10 - 60 * sys_tz), &v5);
  result = scnprintf(a1, a2, "[%02d:%02d:%02d.%06lu]", v6, HIDWORD(v5), v5, v11 / 1000);
  _ReadStatusReg(SP_EL0);
  return result;
}
