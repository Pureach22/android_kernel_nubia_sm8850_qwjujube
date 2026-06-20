__int64 dynamic_page_pool_init_shrinker()
{
  __int64 v1; // x0

  if ( (dynamic_page_pool_init_shrinker_registered & 1) != 0 )
    return 0;
  v1 = shrinker_alloc(0, "dynamic_page_pool");
  pool_shrinker = v1;
  if ( !v1 )
    return 4294967284LL;
  *(_QWORD *)v1 = dynamic_page_pool_shrink_count;
  *(_QWORD *)(v1 + 8) = dynamic_page_pool_shrink_scan;
  *(_DWORD *)(v1 + 24) = 2;
  shrinker_register();
  dynamic_page_pool_init_shrinker_registered = 1;
  return 0;
}
