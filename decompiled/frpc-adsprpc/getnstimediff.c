unsigned __int64 __fastcall getnstimediff(__int64 *a1)
{
  __int64 v2; // x10
  __int64 v3; // x11
  unsigned __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-28h] BYREF
  __int64 v6; // [xsp+10h] [xbp-20h]
  __int64 v7; // [xsp+18h] [xbp-18h] BYREF
  __int64 v8; // [xsp+20h] [xbp-10h]
  __int64 v9; // [xsp+28h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v6 = 0;
  ktime_get_real_ts64(&v5);
  v2 = *a1;
  v3 = a1[1];
  v7 = 0;
  v8 = 0;
  set_normalized_timespec64(&v7, v5 - v2, v6 - v3);
  if ( v7 <= 0x225C17D03LL )
  {
    if ( v7 >= (__int64)0xFFFFFFFDDA3E82FDLL )
      result = v8 + 1000000000 * v7;
    else
      result = 0x8000000000000000LL;
  }
  else
  {
    result = 0x7FFFFFFFFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
