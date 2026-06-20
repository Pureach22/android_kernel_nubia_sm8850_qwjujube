__int64 sub_12273C()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x126078);
  return perf_trace_kgsl_timeline_fence_alloc();
}
