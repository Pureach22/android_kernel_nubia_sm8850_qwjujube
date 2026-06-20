__int64 __fastcall synx_util_generate_timestamp(char *a1, size_t a2)
{
  __int64 result; // x0
  __int64 v5; // [xsp+0h] [xbp-40h] BYREF
  __int64 v6; // [xsp+8h] [xbp-38h]
  __int64 v7; // [xsp+10h] [xbp-30h]
  __int64 v8; // [xsp+18h] [xbp-28h]
  __int64 v9; // [xsp+20h] [xbp-20h]
  _QWORD v10[3]; // [xsp+28h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v10[1] = 0;
  v8 = 0;
  v9 = 0;
  v6 = 0;
  v7 = 0;
  v5 = 0;
  ktime_get_real_ts64(v10);
  time64_to_tm(v10[0], 0, &v5);
  result = snprintf(a1, a2, "%02d-%02d %02d:%02d:%02d", v7 + 1, HIDWORD(v6), v6, HIDWORD(v5), v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
