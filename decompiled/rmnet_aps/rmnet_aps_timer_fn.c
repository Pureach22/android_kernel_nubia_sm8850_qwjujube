__int64 rmnet_aps_timer_fn()
{
  return queue_work_on(32, system_wq, &rmnet_aps_flow_expire_work);
}
