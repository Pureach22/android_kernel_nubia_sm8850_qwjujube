__int64 sched_full_throttle_boost_enter()
{
  __int64 result; // x0

  result = core_ctl_set_boost(1);
  sched_freq_aggr_en = 1;
  return result;
}
