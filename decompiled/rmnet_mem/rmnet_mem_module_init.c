// Alternative name is 'init_module'
__int64 rmnet_mem_module_init()
{
  __int64 v0; // x8
  _QWORD *v1; // x11
  _QWORD *v2; // x12

  printk(&unk_98DE, "rmnet_mem_module_init");
  v0 = 0;
  do
  {
    v1 = (_QWORD *)((char *)&rmnet_mem_pool + v0);
    v2 = (_QWORD *)((char *)&rmnet_mem_cache + v0);
    v0 += 16;
    *v1 = v1;
    v1[1] = v1;
    *v2 = v2;
    v2[1] = v2;
  }
  while ( v0 != 64 );
  mem_wq = alloc_workqueue("mem_wq", 16, 0);
  if ( mem_wq )
  {
    pool_adjust_work = 0xFFFFFFFE00000LL;
    qword_8EF0 = (__int64)&qword_8EF0;
    qword_8EF8 = (__int64)&qword_8EF0;
    qword_8F00 = (__int64)mem_update_pool_work;
    init_timer_key(&unk_8F08, &delayed_work_timer_fn, 0x200000, 0, 0);
    pool_replenish_work = 0xFFFFFFFE00000LL;
    qword_8E80 = (__int64)&qword_8E80;
    qword_8E88 = (__int64)&qword_8E80;
    qword_8E90 = (__int64)mem_replenish_work;
    init_timer_key(&unk_8E98, &delayed_work_timer_fn, 0x200000, 0, 0);
    if ( !(unsigned int)rmnet_mem_nl_register() )
    {
      hrtimer_init(&pb_timer, 1, 1);
      qword_8F98 = (__int64)rmnet_mem_pb_timer_cb;
      return 0;
    }
    printk(&unk_992F, "rmnet_mem_module_init");
    destroy_workqueue(mem_wq);
    mem_wq = 0;
  }
  return 4294967284LL;
}
