__int64 __fastcall adreno_hwsched_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned __int64 worker; // x0
  __int64 result; // x0
  __int64 v7; // x8
  _QWORD v8[4]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v9[5]; // [xsp+28h] [xbp-28h] BYREF

  v9[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset((void *)(a1 + 20904), 0, 0xBF8u);
  v4 = _kmalloc_cache_noprof(icc_set_bw, 3520, 1024);
  *(_QWORD *)(a1 + 22792) = v4;
  if ( v4 )
  {
    worker = kthread_create_worker(0, "kgsl_hwsched");
    *(_QWORD *)(a1 + 24400) = worker;
    if ( worker < 0xFFFFFFFFFFFFF001LL )
    {
      _mutex_init(a1 + 22448, "&hwsched->mutex", &adreno_hwsched_init___key);
      *(_QWORD *)(a1 + 24440) = 0;
      *(_QWORD *)(a1 + 24432) = 0;
      *(_QWORD *)(a1 + 24408) = a1 + 24408;
      *(_QWORD *)(a1 + 24416) = a1 + 24408;
      *(_QWORD *)(a1 + 24424) = adreno_hwsched_work;
      memset(&v9[1], 0, 24);
      v9[0] = 8;
      jobs_cache_0 = _kmem_cache_create_args("adreno_dispatch_job", 16, v9, 0);
      memset(&v8[1], 0, 24);
      v8[0] = 8;
      obj_cache = _kmem_cache_create_args("cmd_list_obj", 24, v8, 0);
      *(_QWORD *)(a1 + 22768) = a1 + 22768;
      *(_QWORD *)(a1 + 22776) = a1 + 22768;
      v7 = *(_QWORD *)(a1 + 24400);
      *(_QWORD *)(a1 + 22512) = 0;
      *(_QWORD *)(a1 + 22520) = 0;
      *(_QWORD *)(a1 + 22528) = 0;
      *(_QWORD *)(a1 + 22536) = 0;
      *(_QWORD *)(a1 + 22544) = 0;
      *(_QWORD *)(a1 + 22552) = 0;
      *(_QWORD *)(a1 + 22560) = 0;
      *(_QWORD *)(a1 + 22568) = 0;
      *(_QWORD *)(a1 + 22576) = 0;
      *(_QWORD *)(a1 + 22584) = 0;
      *(_QWORD *)(a1 + 22592) = 0;
      *(_QWORD *)(a1 + 22600) = 0;
      *(_QWORD *)(a1 + 22608) = 0;
      *(_QWORD *)(a1 + 22616) = 0;
      *(_QWORD *)(a1 + 22624) = 0;
      *(_QWORD *)(a1 + 22632) = 0;
      *(_QWORD *)(a1 + 22640) = 0;
      *(_QWORD *)(a1 + 22648) = 0;
      *(_QWORD *)(a1 + 22656) = 0;
      *(_QWORD *)(a1 + 22664) = 0;
      *(_QWORD *)(a1 + 22672) = 0;
      *(_QWORD *)(a1 + 22680) = 0;
      *(_QWORD *)(a1 + 22688) = 0;
      *(_QWORD *)(a1 + 22696) = 0;
      *(_QWORD *)(a1 + 22704) = 0;
      *(_QWORD *)(a1 + 22712) = 0;
      *(_QWORD *)(a1 + 22720) = 0;
      *(_QWORD *)(a1 + 22728) = 0;
      *(_QWORD *)(a1 + 22736) = 0;
      *(_QWORD *)(a1 + 22744) = 0;
      *(_QWORD *)(a1 + 22752) = 0;
      *(_QWORD *)(a1 + 22760) = 0;
      sched_set_fifo(*(_QWORD *)(v7 + 40));
      if ( (unsigned int)sysfs_create_files(*(_QWORD *)a1, hwsched_attr_list) )
        __break(0x800u);
      *(_QWORD *)(a1 + 20896) = hwsched_ops;
      *(_QWORD *)(a1 + 22784) = a2;
      *(_DWORD *)(a1 + 22800) = 0;
      _init_swait_queue_head(a1 + 22808, "&x->wait", &init_completion___key_4);
      complete_all(a1 + 22800);
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x80) != 0 )
      {
        *(_QWORD *)(a1 + 22888) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(a1 + 22896) = a1 + 22896;
        *(_QWORD *)(a1 + 22904) = a1 + 22896;
        *(_QWORD *)(a1 + 22912) = hwsched_lsr_check;
        init_timer_key(a1 + 22848, hwsched_lsr_timer, 0, 0, 0);
      }
      _init_waitqueue_head(a1 + 23160, "&hwf->unack_wq", &adreno_hwsched_init___key_8);
      result = 0;
      *(_DWORD *)(a1 + 23152) = 0;
    }
    else
    {
      kfree(*(_QWORD *)(a1 + 22792));
      result = *(unsigned int *)(a1 + 24400);
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
