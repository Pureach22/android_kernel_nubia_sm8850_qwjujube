__int64 kgsl_events_exit()
{
  return kmem_cache_destroy(events_cache);
}
