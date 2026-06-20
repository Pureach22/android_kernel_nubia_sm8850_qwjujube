__int64 __usercall sub_38D9C@<X0>(int a1@<W8>)
{
  if ( !a1 )
    JUMPOUT(0xD220);
  return trace_event_raw_event_core_ctl_set_boost();
}
