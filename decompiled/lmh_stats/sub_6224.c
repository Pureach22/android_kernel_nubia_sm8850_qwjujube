__int64 sub_6224()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x9B60);
  return _bpf_trace_thermal_hw_freq_limit();
}
