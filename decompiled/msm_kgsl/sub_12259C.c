__int64 sub_12259C()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x125ED8);
  return perf_trace_kgsl_timeline_signal();
}
