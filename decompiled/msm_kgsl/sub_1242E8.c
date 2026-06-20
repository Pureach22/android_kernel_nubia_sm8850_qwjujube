__int64 sub_1242E8()
{
  __int64 v0; // x30

  if ( (v0 & 0x400000000000000LL) == 0 )
    JUMPOUT(0x127C24);
  return _bpf_trace_kgsl_timeline_fence_alloc();
}
