__int64 icnss_debug_deinit()
{
  __int64 result; // x0

  if ( icnss_ipc_log_context )
  {
    ipc_log_context_destroy();
    icnss_ipc_log_context = 0;
  }
  if ( icnss_ipc_log_long_context )
  {
    ipc_log_context_destroy();
    icnss_ipc_log_long_context = 0;
  }
  if ( icnss_ipc_log_smp2p_context )
  {
    ipc_log_context_destroy();
    icnss_ipc_log_smp2p_context = 0;
  }
  result = icnss_ipc_soc_wake_context;
  if ( icnss_ipc_soc_wake_context )
  {
    result = ipc_log_context_destroy();
    icnss_ipc_soc_wake_context = 0;
  }
  return result;
}
