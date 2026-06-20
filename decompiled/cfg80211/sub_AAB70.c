__int64 sub_AAB70()
{
  __int64 v0; // x21

  if ( (v0 & 0x200000000000000LL) == 0 )
    JUMPOUT(0xABA98);
  return _bpf_trace_rdev_assoc();
}
