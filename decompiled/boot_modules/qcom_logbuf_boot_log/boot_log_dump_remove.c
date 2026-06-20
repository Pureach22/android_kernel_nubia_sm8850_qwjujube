// Alternative name is 'cleanup_module'
__int64 boot_log_dump_remove()
{
  if ( dump_thread )
    kthread_stop();
  return kfree(boot_log_buf);
}
