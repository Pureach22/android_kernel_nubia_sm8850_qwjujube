__int64 aps_data_inactive()
{
  raw_spin_lock_bh(&dl_activity_lock);
  last_inactive_ts = ktime_get_coarse_with_offset(1);
  return raw_spin_unlock_bh(&dl_activity_lock);
}
