__int64 __fastcall athdiag_procfs_init(__int64 a1)
{
  __int64 v2; // x0
  const char *v4; // x19
  __int64 v5; // x1

  v2 = proc_mkdir("cldpeach_v2", 0);
  proc_dir = v2;
  if ( v2 )
  {
    proc_file = proc_create_data("athdiagpfs", 384, v2, &athdiag_fops, a1);
    if ( proc_file )
    {
      qdf_trace_msg(61, 8, "%s: /proc/%s/%s created", "athdiag_procfs_init", "cldpeach_v2", "athdiagpfs");
      return 0;
    }
    v5 = proc_dir;
    v4 = "athdiagpfs";
  }
  else
  {
    v4 = "cldpeach_v2";
    v5 = 0;
  }
  remove_proc_entry(v4, v5);
  qdf_trace_msg(61, 2, "%s: Could not initialize /proc/%s", "athdiag_procfs_init", v4);
  return 4294967284LL;
}
