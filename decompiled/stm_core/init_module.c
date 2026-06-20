__int64 init_module()
{
  unsigned int v0; // w19

  v0 = class_register(&stm_class);
  if ( !v0 )
  {
    v0 = class_register(&stm_source_class);
    if ( !v0 )
    {
      v0 = stp_configfs_init();
      if ( !v0 )
      {
        init_srcu_struct(&stm_source_srcu);
        stm_pdrv_head = (__int64)&stm_pdrv_head;
        qword_9C70 = (__int64)&stm_pdrv_head;
        _mutex_init(&stm_pdrv_mutex, "&stm_pdrv_mutex", &stm_core_init___key);
        ++stm_core_up;
        return v0;
      }
      class_unregister(&stm_source_class);
    }
    class_unregister(&stm_class);
  }
  return v0;
}
