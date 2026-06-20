__int64 __fastcall adreno_dispatcher_init(_QWORD *a1)
{
  __int64 result; // x0
  unsigned __int64 worker; // x0
  __int64 args; // x0
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned __int64 v13; // x9
  _QWORD v14[5]; // [xsp+8h] [xbp-28h] BYREF

  v14[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a1[2476] & 4) != 0 )
    goto LABEL_8;
  result = kobject_init_and_add(a1 + 2520, &ktype_dispatcher, *a1, "dispatch");
  if ( !(_DWORD)result )
  {
    worker = kthread_create_worker(result, "kgsl_dispatcher");
    a1[3050] = worker;
    if ( worker >= 0xFFFFFFFFFFFFF001LL )
    {
      kobject_put(a1 + 2520);
      result = *((unsigned int *)a1 + 6100);
      goto LABEL_9;
    }
    if ( (unsigned int)sysfs_create_files(*a1, dispatch_attr_list) )
      __break(0x800u);
    _mutex_init(a1 + 2470, "&dispatcher->mutex", &adreno_dispatcher_init___key);
    init_timer_key(a1 + 2477, adreno_dispatcher_timer, 0, 0, 0);
    a1[3055] = 0;
    a1[3054] = 0;
    a1[3051] = a1 + 3051;
    a1[3052] = a1 + 3051;
    *((_DWORD *)a1 + 5064) = 0;
    a1[3053] = adreno_dispatcher_work;
    _init_swait_queue_head(a1 + 2533, "&x->wait", &init_completion___key_1);
    complete_all(a1 + 2532);
    memset(&v14[1], 0, 24);
    v14[0] = 8;
    args = _kmem_cache_create_args("adreno_dispatch_job", 16, v14, 0);
    v5 = a1[3050];
    a1[2488] = 0;
    a1[2489] = 0;
    a1[2490] = 0;
    a1[2491] = 0;
    a1[2492] = 0;
    a1[2493] = 0;
    a1[2494] = 0;
    a1[2495] = 0;
    a1[2496] = 0;
    a1[2497] = 0;
    a1[2498] = 0;
    a1[2499] = 0;
    a1[2500] = 0;
    a1[2501] = 0;
    a1[2502] = 0;
    a1[2503] = 0;
    a1[2504] = 0;
    a1[2505] = 0;
    a1[2506] = 0;
    a1[2507] = 0;
    a1[2508] = 0;
    a1[2509] = 0;
    a1[2510] = 0;
    a1[2511] = 0;
    a1[2512] = 0;
    a1[2513] = 0;
    a1[2514] = 0;
    a1[2515] = 0;
    a1[2516] = 0;
    a1[2517] = 0;
    a1[2518] = 0;
    a1[2519] = 0;
    a1[2612] = swsched_ops;
    v6 = *(_QWORD *)(v5 + 40);
    jobs_cache = args;
    sched_set_fifo(v6);
    _X8 = a1 + 2476;
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 | 4, _X8) );
LABEL_8:
    result = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
