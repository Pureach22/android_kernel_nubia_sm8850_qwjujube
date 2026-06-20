__int64 sub_1221B8()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x125AF4);
  return trace_event_raw_event_kgsl_timeline_alloc();
}
