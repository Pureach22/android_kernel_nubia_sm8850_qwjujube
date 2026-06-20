__int64 athdiag_procfs_remove()
{
  __int64 result; // x0

  if ( proc_dir )
  {
    remove_proc_entry("athdiagpfs", proc_dir);
    qdf_trace_msg(61, 8, "%s: /proc/%s/%s removed", "athdiag_procfs_remove", "cldpeach_v2", "athdiagpfs");
    remove_proc_entry("cldpeach_v2", 0);
    result = qdf_trace_msg(61, 8, "%s: /proc/%s removed", "athdiag_procfs_remove", "cldpeach_v2");
    proc_dir = 0;
  }
  return result;
}
