bool __fastcall hdd_wait_for_debugfs_threads_completion(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  bool v8; // w22
  int v9; // w23

  v8 = debugfs_thread_count == 0;
  if ( debugfs_thread_count )
  {
    v9 = -20;
    while ( !__CFADD__(v9++, 1) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Waiting for %d debugfs threads to exit",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "hdd_wait_for_debugfs_threads_completion");
      qdf_sleep();
      v8 = debugfs_thread_count == 0;
      if ( !debugfs_thread_count )
        return v8;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Timed-out waiting for debugfs threads",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "hdd_wait_for_debugfs_threads_completion");
  }
  return v8;
}
