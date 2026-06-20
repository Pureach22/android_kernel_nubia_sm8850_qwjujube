__int64 sched_full_throttle_boost_exit()
{
  __int64 result; // x0

  result = core_ctl_set_boost(0);
  sched_freq_aggr_en = 0;
  return result;
}
