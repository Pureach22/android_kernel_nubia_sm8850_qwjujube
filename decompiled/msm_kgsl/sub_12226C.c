__int64 sub_12226C()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x125BA8);
  return perf_trace_kgsl_timeline_alloc();
}
