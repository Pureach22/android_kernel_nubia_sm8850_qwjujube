__int64 cleanup_module()
{
  if ( glink_ilc )
    ipc_log_context_destroy();
  return platform_driver_unregister(glink_probe_driver);
}
