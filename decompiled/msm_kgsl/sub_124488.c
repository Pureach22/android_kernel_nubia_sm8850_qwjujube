__int64 sub_124488()
{
  __int64 v0; // x24

  if ( (v0 & 0x200000000LL) != 0 )
    JUMPOUT(0x11E16C);
  return _bpf_trace_kgsl_reclaim_memdesc();
}
