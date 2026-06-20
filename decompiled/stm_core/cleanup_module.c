__int64 cleanup_module()
{
  __int64 v0; // x0

  cleanup_srcu_struct(&stm_source_srcu);
  class_unregister(&stm_source_class);
  v0 = class_unregister(&stm_class);
  return stp_configfs_exit(v0);
}
