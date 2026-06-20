__int64 sub_11F5E4()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x122F20);
  return trace_event_raw_event_kgsl_mem_sync_full_cache();
}
