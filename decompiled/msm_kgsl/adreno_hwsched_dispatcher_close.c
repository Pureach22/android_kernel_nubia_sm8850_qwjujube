__int64 __fastcall adreno_hwsched_dispatcher_close(_QWORD *a1)
{
  unsigned __int64 v2; // x0

  v2 = a1[3050];
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    kthread_destroy_worker(v2);
  a1[2612] = 0;
  kmem_cache_destroy(jobs_cache_0);
  kmem_cache_destroy(obj_cache);
  sysfs_remove_files(*a1, hwsched_attr_list);
  kfree(a1[2849]);
  adreno_hwsched_deregister_hw_fence((__int64)a1);
  if ( a1[2868] )
    kgsl_sharedmem_free(a1 + 2867);
  kobject_put(a1 + 2958);
  return kobject_put(a1 + 2946);
}
