bool __fastcall should_boost_bus_dcvs(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x0

  if ( walt_clock_suspended == 1 )
    v2 = sched_clock_last;
  else
    v2 = sched_clock(a1, a2);
  if ( oscillate_ts_ns + 16000000 >= v2 )
    return 1;
  return trailblazer_boost_state_ns + 100000000 >= v2 || sbt_boost_ns + 40000000 >= v2 || sched_boost_type == 4;
}
