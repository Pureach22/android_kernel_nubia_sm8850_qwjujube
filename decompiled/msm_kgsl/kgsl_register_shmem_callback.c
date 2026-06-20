__int64 kgsl_register_shmem_callback()
{
  return android_rvh_probe_register(&_tracepoint_android_rvh_shmem_get_folio, kgsl_shmem_fill_page, 0);
}
