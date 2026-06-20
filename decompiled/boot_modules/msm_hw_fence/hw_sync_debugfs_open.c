__int64 __fastcall hw_sync_debugfs_open(__int64 a1, __int64 a2)
{
  __int64 *v3; // x20
  __int64 v4; // x8

  v3 = (__int64 *)_kmalloc_cache_noprof(kfree, 3520, 56);
  if ( !v3 )
    return 4294967284LL;
  v4 = dma_fence_context_alloc(1);
  *(_QWORD *)(a2 + 32) = v3;
  *v3 = v4;
  return 0;
}
