__int64 clk_debug_exit()
{
  _QWORD *v0; // x0
  _QWORD *v1; // x9
  _QWORD *v2; // x21
  _QWORD *v3; // x8

  debugfs_remove(clk_debugfs_suspend);
  debugfs_remove(clk_debugfs_suspend_atomic);
  tracepoint_probe_unregister(&_tracepoint_suspend_resume, clk_debug_suspend_trace_probe, 0);
  mutex_lock(&clk_debug_lock);
  v0 = clk_hw_debug_list;
  if ( clk_hw_debug_list != (_UNKNOWN *)&clk_hw_debug_list )
  {
    do
    {
      v2 = (_QWORD *)*v0;
      if ( v0 )
      {
        v3 = (_QWORD *)v0[1];
        if ( (_QWORD *)*v3 == v0 && (_QWORD *)v2[1] == v0 )
        {
          v2[1] = v3;
          *v3 = v2;
        }
        else
        {
          _list_del_entry_valid_or_report();
          v0 = v1;
        }
        *v0 = 0xDEAD000000000100LL;
        v0[1] = 0xDEAD000000000122LL;
        kfree();
      }
      v0 = v2;
    }
    while ( v2 != &clk_hw_debug_list );
  }
  return mutex_unlock(&clk_debug_lock);
}
