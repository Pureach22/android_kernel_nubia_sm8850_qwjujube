__int64 sub_11F698()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x122FD4);
  return perf_trace_kgsl_mem_sync_full_cache();
}
