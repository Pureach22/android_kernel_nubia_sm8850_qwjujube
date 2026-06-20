__int64 __usercall sub_38E4C@<X0>(int a1@<W8>)
{
  if ( !a1 )
    JUMPOUT(0xD2D0);
  return perf_trace_core_ctl_set_boost();
}
