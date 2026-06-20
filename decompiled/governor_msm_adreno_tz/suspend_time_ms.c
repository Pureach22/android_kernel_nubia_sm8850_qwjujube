__int64 suspend_time_ms()
{
  __int64 v0; // x8
  __int64 result; // x0

  if ( !suspend_start )
    return 0;
  v0 = ktime_get() / 1000000;
  result = v0 - suspend_start;
  suspend_start = v0;
  return result;
}
