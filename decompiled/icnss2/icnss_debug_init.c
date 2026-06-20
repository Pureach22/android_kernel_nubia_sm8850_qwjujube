__int64 icnss_debug_init()
{
  __int64 result; // x0

  icnss_ipc_log_context = ipc_log_context_create(10, "icnss", 0);
  if ( !icnss_ipc_log_context )
  {
    printk("%sUnable to create log context\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sUnable to create log context\n", (const char *)&unk_12DBF3);
  }
  icnss_ipc_log_long_context = ipc_log_context_create(4, "icnss_long", 0);
  if ( !icnss_ipc_log_long_context )
  {
    printk("%sUnable to create log long context\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sUnable to create log long context\n", (const char *)&unk_12DBF3);
  }
  icnss_ipc_log_smp2p_context = ipc_log_context_create(4, "icnss_smp2p", 0);
  if ( !icnss_ipc_log_smp2p_context )
  {
    printk("%sUnable to create log smp2p context\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sUnable to create log smp2p context\n", (const char *)&unk_12DBF3);
  }
  result = ipc_log_context_create(4, "icnss_soc_wake", 0);
  icnss_ipc_soc_wake_context = result;
  if ( !result )
  {
    printk("%sUnable to create log soc_wake context\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, "%sUnable to create log soc_wake context\n", (const char *)&unk_12DBF3);
  }
  return result;
}
