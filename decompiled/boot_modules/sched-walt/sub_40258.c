__int64 __usercall sub_40258@<X0>(int a1@<W8>)
{
  if ( !a1 )
    JUMPOUT(0x146DC);
  return _bpf_trace_core_ctl_set_boost();
}
