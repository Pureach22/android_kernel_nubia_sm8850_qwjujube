__int64 cnss_debug_deinit()
{
  __int64 result; // x0

  if ( cnss_ipc_log_long_context )
  {
    ipc_log_context_destroy(cnss_ipc_log_long_context);
    cnss_ipc_log_long_context = 0;
  }
  result = cnss_ipc_log_context;
  if ( cnss_ipc_log_context )
  {
    result = ipc_log_context_destroy(cnss_ipc_log_context);
    cnss_ipc_log_context = 0;
  }
  return result;
}
