__int64 rmnet_offload_engine_enable_chain_flush()
{
  return rmnet_module_hook_register(&rmnet_offload_engine_hook, 1);
}
