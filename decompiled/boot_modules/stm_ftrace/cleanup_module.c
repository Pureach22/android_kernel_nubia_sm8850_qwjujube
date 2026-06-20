__int64 cleanup_module()
{
  return stm_source_unregister_device(&stm_ftrace);
}
