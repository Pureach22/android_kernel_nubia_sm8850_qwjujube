void rmnet_mem_pb_ind()
{
  if ( rmnet_mem_pb_enable || qword_8F68 )
  {
    pb_ind_pending = 1;
    if ( (hrtimer_active(&pb_timer) & 1) != 0 )
    {
      hrtimer_cancel(&pb_timer);
    }
    else
    {
      cancel_delayed_work(&pool_adjust_work);
      queue_delayed_work_on(32, mem_wq, &pool_adjust_work, 0);
    }
    ++rmnet_mem_stats;
    hrtimer_start_range_ns(&pb_timer, 105000000, 0, 3);
  }
}
