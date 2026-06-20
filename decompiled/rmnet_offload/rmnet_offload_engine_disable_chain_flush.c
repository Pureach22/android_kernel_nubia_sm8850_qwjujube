__int64 rmnet_offload_engine_disable_chain_flush()
{
  return rmnet_module_hook_unregister_no_sync(&rmnet_offload_engine_hook, 1);
}
