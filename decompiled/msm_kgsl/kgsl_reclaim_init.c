__int64 kgsl_reclaim_init()
{
  _QWORD *v0; // x0
  __int64 result; // x0

  v0 = (_QWORD *)shrinker_alloc(0, "kgsl_reclaim_shrinker");
  qword_3A918 = (__int64)v0;
  if ( v0 )
  {
    *v0 = kgsl_reclaim_shrink_count_objects;
    *(_QWORD *)(qword_3A918 + 8) = kgsl_reclaim_shrink_scan_objects;
    *(_DWORD *)(qword_3A918 + 24) = 2;
    *(_QWORD *)(qword_3A918 + 16) = 0;
    shrinker_register(qword_3A918);
    result = 0;
    reclaim_work = 0xFFFFFFFE00000LL;
    qword_17D1D0 = (__int64)&qword_17D1D0;
    qword_17D1D8 = (__int64)&qword_17D1D0;
    qword_17D1E0 = (__int64)&kgsl_reclaim_background_work;
  }
  else
  {
    printk(&unk_143136);
    return 4294967284LL;
  }
  return result;
}
