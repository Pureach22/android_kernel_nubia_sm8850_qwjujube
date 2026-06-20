__int64 nbia_init()
{
  __int64 v0; // x0
  unsigned __int64 v2; // x0
  void *v3; // x0

  sched_nbia_render_tid_array = 0;
  sched_early_up_migrate = 0;
  sched_early_down_migrate = 0;
  memset(sched_prio_adjusted_info, 0, 0x1F4u);
  memset(&cmask_bundles, 0, 0x320u);
  memset(&scp_udata, 0, 0x110u);
  bundles_array_index = 0;
  qword_6A598 = 32000000;
  ring_array_index = 0;
  sched_nbia_debug = 0;
  sched_nbia_class_persisted_debug = 0;
  sched_nbia_queuework_enable = 1;
  sched_nbia_rate_tns = 0;
  _kthread_init_worker(&worker, "(&worker)->lock", &nbia_init___key);
  mutex_lock(&r_buffer_lock);
  if ( !r_buffer )
    r_buffer = createRingBuffer(10000);
  mutex_unlock(&r_buffer_lock);
  v0 = kobject_create_and_add("nbia", 0);
  nbia_kobj = v0;
  if ( !v0 )
    return printk(&unk_63A4A);
  if ( (unsigned int)sysfs_create_group(v0, &nbia_attr_group) )
  {
    v3 = &unk_62EEC;
  }
  else
  {
    tracepoint_probe_register(&_tracepoint_android_vh_sched_setaffinity_early, nbia_sched_setaffinity_early, 0);
    v2 = kthread_create_on_node(&kthread_worker_fn, &worker, 0xFFFFFFFFLL, "kthread_nbia_walt");
    thread = v2;
    if ( v2 >= 0xFFFFFFFFFFFFF001LL )
    {
      kthread_running = 0;
      return printk(&unk_67AD7);
    }
    wake_up_process(v2);
    v3 = &unk_67677;
    kthread_running = 1;
  }
  return printk(v3);
}
