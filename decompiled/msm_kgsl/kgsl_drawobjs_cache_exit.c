__int64 kgsl_drawobjs_cache_exit()
{
  return kmem_cache_destroy(memobjs_cache);
}
