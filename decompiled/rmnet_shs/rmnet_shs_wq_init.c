void rmnet_shs_wq_init()
{
  _QWORD *v0; // x0

  if ( !rmnet_shs_wq )
  {
    rmnet_shs_wq = alloc_workqueue("rmnet_shs_wq", 2, 1);
    if ( rmnet_shs_wq )
    {
      v0 = (_QWORD *)_kmalloc_cache_noprof(_rcu_read_lock, 2080, 104);
      rmnet_shs_delayed_wq = (__int64)v0;
      if ( v0 )
      {
        *v0 = 0xFFFFFFFE00000LL;
        v0[1] = v0 + 1;
        v0[2] = v0 + 1;
        v0[3] = rmnet_shs_wq_process_wq;
        init_timer_key(v0 + 4, &delayed_work_timer_fn, 0x200000, 0, 0);
      }
      else
      {
        ++qword_1A3F8;
        rmnet_shs_wq_exit();
      }
    }
    else
    {
      ++qword_1A3F0;
    }
  }
}
