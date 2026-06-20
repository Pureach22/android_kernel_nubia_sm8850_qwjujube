__int64 __fastcall ktime_get_boottime_ts64(__int64 *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x1

  v2 = ktime_get_with_offset(1);
  result = ns_to_timespec64(v2);
  *a1 = result;
  a1[1] = v4;
  return result;
}
