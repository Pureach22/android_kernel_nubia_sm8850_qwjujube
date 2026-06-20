__int64 sub_6084()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x99C0);
  return trace_event_raw_event_thermal_hw_freq_limit();
}
