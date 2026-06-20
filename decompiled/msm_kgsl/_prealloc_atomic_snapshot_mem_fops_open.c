__int64 __fastcall prealloc_atomic_snapshot_mem_fops_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, prealloc_atomic_snap_mem_get, prealloc_atomic_snap_mem_set, "%llu\n", a6);
}
