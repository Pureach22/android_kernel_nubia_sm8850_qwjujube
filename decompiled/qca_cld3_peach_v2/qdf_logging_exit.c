__int64 qdf_logging_exit()
{
  __int64 v0; // x0
  __int64 v1; // x0

  v0 = wlan_logging_notifier_deinit((unsigned __int8)qdf_log_dump_at_kernel_enable);
  v1 = nl_srv_exit(v0);
  return wlan_logging_sock_deinit_svc(v1);
}
