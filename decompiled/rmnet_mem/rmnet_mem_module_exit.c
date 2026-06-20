// Alternative name is 'cleanup_module'
__int64 rmnet_mem_module_exit()
{
  rmnet_mem_nl_unregister();
  if ( mem_wq )
  {
    cancel_delayed_work_sync(&pool_adjust_work);
    drain_workqueue(mem_wq);
    destroy_workqueue(mem_wq);
    mem_wq = 0;
  }
  return rmnet_mem_free_all();
}
