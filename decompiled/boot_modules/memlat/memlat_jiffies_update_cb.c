__int64 memlat_jiffies_update_cb()
{
  __int64 result; // x0
  __int64 v1; // x19

  result = ktime_get();
  if ( *(_BYTE *)(memlat_data + 307) == 1 )
  {
    v1 = result;
    if ( result - *(_QWORD *)(memlat_data + 240) + 2000000 > 1000000LL * *(unsigned int *)(memlat_data + 160) )
    {
      result = hrtimer_start_range_ns(memlat_data + 168, 100000, 0, 3);
      *(_QWORD *)(memlat_data + 240) = v1;
    }
  }
  return result;
}
