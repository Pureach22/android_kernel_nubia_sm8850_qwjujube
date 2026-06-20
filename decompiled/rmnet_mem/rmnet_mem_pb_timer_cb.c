__int64 rmnet_mem_pb_timer_cb()
{
  pb_ind_pending = 0;
  queue_delayed_work_on(32, mem_wq, &pool_adjust_work, 750);
  return 0;
}
