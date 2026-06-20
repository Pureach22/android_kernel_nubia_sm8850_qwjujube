__int64 rmnet_perf_udp_exit()
{
  cancel_delayed_work_sync(&rmnet_perf_udp_work);
  byte_EAA0 = 1;
  queue_delayed_work_on(32, system_wq, &rmnet_perf_udp_work, 0);
  return cancel_delayed_work_sync(&rmnet_perf_udp_work);
}
