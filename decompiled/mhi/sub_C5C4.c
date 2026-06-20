__int64 sub_C5C4()
{
  __int64 v0; // x25

  if ( (v0 & 0x20000000000LL) == 0 )
    JUMPOUT(0xCACC);
  return perf_trace_mhi_process_event_ring();
}
