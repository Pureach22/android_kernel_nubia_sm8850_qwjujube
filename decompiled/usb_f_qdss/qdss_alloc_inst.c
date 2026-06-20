__int64 qdss_alloc_inst()
{
  __int64 v0; // x0
  __int64 v1; // x19

  v0 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 192);
  if ( !v0 )
    return -12;
  *(_QWORD *)(v0 + 160) = usb_qdss_set_inst_name;
  *(_QWORD *)(v0 + 168) = usb_qdss_free_inst;
  v1 = v0;
  config_group_init_type_name();
  return v1;
}
