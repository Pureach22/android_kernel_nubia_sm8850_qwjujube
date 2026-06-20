__int64 __fastcall dfs_create_object(__int64 a1)
{
  void *v2; // x0

  *(_QWORD *)a1 = &global_dfs;
  qdf_mem_set(&global_dfs, 0x3AB8u, 0);
  *(_QWORD *)(*(_QWORD *)a1 + 14888LL) = &global_dfs_curchan;
  if ( !*(_QWORD *)(*(_QWORD *)a1 + 14888LL) )
    return 1;
  *(_QWORD *)(*(_QWORD *)a1 + 14896LL) = &global_dfs_prevchan;
  v2 = *(void **)(*(_QWORD *)a1 + 14896LL);
  if ( !v2 )
    return 1;
  qdf_mem_set(v2, 0x20u, 0);
  return 0;
}
