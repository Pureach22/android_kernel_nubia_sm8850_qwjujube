__int64 cleanup_module()
{
  __int64 v0; // x0
  __int64 result; // x0

  platform_driver_unregister(qsee_ipc_irq_bridge_driver);
  v0 = qiib_info;
  if ( !*(_QWORD *)(qiib_info + 88) )
  {
    ipc_log_context_destroy(0);
    v0 = qiib_info;
  }
  result = kfree(v0);
  qiib_info = 0;
  return result;
}
