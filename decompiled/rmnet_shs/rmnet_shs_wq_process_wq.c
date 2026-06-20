__int64 rmnet_shs_wq_process_wq()
{
  __int64 v0; // x0

  ++rmnet_shs_wq_tick;
  raw_spin_lock_bh(&rmnet_shs_ep_lock);
  rmnet_shs_wq_update_stats();
  raw_spin_unlock_bh(&rmnet_shs_ep_lock);
  v0 = _msecs_to_jiffies((unsigned int)rmnet_shs_wq_interval_ms);
  return queue_delayed_work_on(32, rmnet_shs_wq, rmnet_shs_delayed_wq, v0);
}
