__int64 sub_123944()
{
  __int64 v0; // x24

  if ( (v0 & 0x200000000LL) != 0 )
    JUMPOUT(0x11D628);
  return perf_trace_kgsl_reclaim_memdesc();
}
