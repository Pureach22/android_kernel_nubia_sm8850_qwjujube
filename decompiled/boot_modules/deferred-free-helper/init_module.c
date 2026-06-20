__int64 init_module()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x19
  __int64 v2; // x0

  list_nr_pages = 0;
  _init_waitqueue_head(&freelist_waitqueue, "&freelist_waitqueue", &deferred_freelist_init___key);
  v0 = kthread_create_on_node(deferred_free_thread, 0, 0xFFFFFFFFLL, &unk_6570, "dmabuf-deferred-free-worker");
  if ( v0 >= 0xFFFFFFFFFFFFF001LL )
  {
    freelist_task = v0;
    printk(&unk_6544);
    return (unsigned int)freelist_task;
  }
  else
  {
    v1 = v0;
    wake_up_process();
    freelist_task = v1;
    sched_set_normal(v1, 19);
    v2 = shrinker_alloc(0, "dmabuf-deferred-free-shrinker");
    freelist_shrinker = v2;
    if ( v2 )
    {
      *(_QWORD *)(v2 + 16) = 0;
      *(_QWORD *)v2 = freelist_shrink_count;
      *(_QWORD *)(v2 + 8) = freelist_shrink_scan;
      *(_DWORD *)(v2 + 24) = 2;
      shrinker_register();
      return 0;
    }
    else
    {
      printk(&unk_65A5);
      kthread_stop(freelist_task);
      return 4294967284LL;
    }
  }
}
