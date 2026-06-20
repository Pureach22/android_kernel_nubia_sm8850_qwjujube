__int64 sub_122828()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x126164);
  return trace_event_raw_event_kgsl_timeline_fence_release();
}
