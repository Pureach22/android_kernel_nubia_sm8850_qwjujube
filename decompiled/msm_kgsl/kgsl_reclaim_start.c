__int64 kgsl_reclaim_start()
{
  _QWORD *v0; // x0

  v0 = (_QWORD *)shrinker_alloc(0, "kgsl_reclaim_shrinker");
  qword_3A918 = (__int64)v0;
  if ( !v0 )
    return 4294967284LL;
  *v0 = kgsl_reclaim_shrink_count_objects;
  *(_QWORD *)(qword_3A918 + 8) = kgsl_reclaim_shrink_scan_objects;
  *(_DWORD *)(qword_3A918 + 24) = 2;
  *(_QWORD *)(qword_3A918 + 16) = 0;
  shrinker_register(qword_3A918);
  return 0;
}
