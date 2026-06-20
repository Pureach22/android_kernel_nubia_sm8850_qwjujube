__int64 cnss_deinitialize_prealloc_pool()
{
  signed int v0; // w22
  __int64 result; // x0
  unsigned int v2; // w9
  __int64 v3; // x8

  if ( cnss_pools )
  {
    if ( cnss_prealloc_pool_size )
    {
      v0 = 0;
      do
      {
        printk(&unk_6BBB, cnss_pools + 96LL * v0 + 12);
        mempool_destroy(*(_QWORD *)(cnss_pools + 96LL * v0 + 64));
        kmem_cache_destroy(*(_QWORD *)(cnss_pools + 96LL * v0 + 72));
        *(_QWORD *)(cnss_pools + 96LL * v0 + 64) = 0;
        *(_QWORD *)(cnss_pools + 96LL * v0 + 72) = 0;
        result = kfree(*(_QWORD *)(cnss_pools + 96LL * v0 + 80));
        v2 = cnss_prealloc_pool_size;
        v3 = cnss_pools + 96LL * v0++;
        *(_QWORD *)(v3 + 80) = 0;
      }
      while ( v0 < v2 );
    }
    mempool_initialization_done = 0;
  }
  return result;
}
