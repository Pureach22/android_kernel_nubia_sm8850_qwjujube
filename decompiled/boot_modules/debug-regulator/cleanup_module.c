__int64 cleanup_module()
{
  __int64 result; // x0

  result = debugfs_remove(regulator_suspend_debugfs);
  if ( debug_suspend == 1 )
    return tracepoint_probe_unregister(&_tracepoint_suspend_resume, regulator_debug_suspend_trace_probe, 0);
  return result;
}
