__int64 gsi_alloc_inst()
{
  __int64 v0; // x0
  __int64 v1; // x19

  v0 = _kmalloc_cache_noprof(config_group_init_type_name, 3520, 184);
  if ( !v0 )
    return -12;
  *(_QWORD *)(v0 + 160) = gsi_set_inst_name;
  *(_QWORD *)(v0 + 168) = &gsi_free_inst;
  v1 = v0;
  config_group_init_type_name();
  return v1;
}
