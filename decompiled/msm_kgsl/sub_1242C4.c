__int64 sub_1242C4()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x127C00);
  return _bpf_trace_kgsl_timeline_signal();
}
