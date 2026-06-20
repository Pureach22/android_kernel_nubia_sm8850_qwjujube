__int64 rmnet_shs_wq_restart()
{
  __int64 result; // x0

  ++rmnet_shs_restart_count;
  if ( rmnet_shs_wq )
  {
    if ( rmnet_shs_delayed_wq )
      return queue_delayed_work_on(32, rmnet_shs_wq, rmnet_shs_delayed_wq, 0);
  }
  return result;
}
