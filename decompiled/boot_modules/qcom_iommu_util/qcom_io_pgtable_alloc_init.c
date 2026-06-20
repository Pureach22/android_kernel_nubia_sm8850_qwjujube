__int64 qcom_io_pgtable_alloc_init()
{
  __int64 v0; // x0

  v0 = shrinker_alloc(0, "io_pgtable_alloc");
  io_pgtable_alloc_shrinker = v0;
  if ( !v0 )
    return 4294967284LL;
  *(_QWORD *)v0 = io_pgtable_alloc_count_objects;
  *(_QWORD *)(v0 + 8) = io_pgtable_alloc_scan_objects;
  *(_DWORD *)(v0 + 24) = 2;
  shrinker_register();
  return 0;
}
