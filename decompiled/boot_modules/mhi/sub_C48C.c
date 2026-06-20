__int64 sub_C48C()
{
  __int64 v0; // x25

  if ( (v0 & 0x20000000000LL) == 0 )
    JUMPOUT(0xC994);
  return trace_event_raw_event_mhi_process_event_ring();
}
