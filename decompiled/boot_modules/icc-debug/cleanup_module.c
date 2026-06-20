__int64 cleanup_module()
{
  __int64 result; // x0

  result = debugfs_remove(dentry_suspend);
  if ( debug_suspend == 1 )
    return tracepoint_probe_unregister(&_tracepoint_suspend_resume, icc_debug_suspend_trace_probe, 0);
  return result;
}
