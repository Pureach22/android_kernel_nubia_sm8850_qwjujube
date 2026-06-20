__int64 qdf_logging_init()
{
  wlan_logging_sock_init_svc();
  nl_srv_init(0, 2);
  wlan_logging_notifier_init((unsigned __int8)qdf_log_dump_at_kernel_enable);
  return wlan_logging_set_flush_timer((unsigned int)qdf_log_flush_timer_period);
}
