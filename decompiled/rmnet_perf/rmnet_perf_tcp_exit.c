__int64 rmnet_perf_tcp_exit()
{
  cancel_delayed_work_sync(&rmnet_perf_quickack_work);
  byte_E9F8 = 1;
  queue_delayed_work_on(32, system_wq, &rmnet_perf_quickack_work, 0);
  return cancel_delayed_work_sync(&rmnet_perf_quickack_work);
}
