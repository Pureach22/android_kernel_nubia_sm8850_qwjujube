__int64 sub_12427C()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x127BB8);
  return _bpf_trace_kgsl_timeline_alloc();
}
