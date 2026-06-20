__int64 cser_alloc_inst()
{
  __int64 v0; // x0
  __int64 v1; // x19

  v0 = _kmalloc_cache_noprof(unregister_chrdev_region, 3520, 200);
  if ( !v0 )
    return -12;
  *(_QWORD *)(v0 + 160) = cser_set_inst_name;
  *(_QWORD *)(v0 + 168) = cser_free_inst;
  v1 = v0;
  config_group_init_type_name();
  return v1;
}
