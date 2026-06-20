__int64 qdf_get_monotonic_boottime_ns()
{
  return ktime_get_with_offset(1);
}
