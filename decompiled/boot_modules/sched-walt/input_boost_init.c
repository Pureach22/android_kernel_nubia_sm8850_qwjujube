__int64 input_boost_init()
{
  char v0; // w8
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x19
  __int64 v3; // x25
  __int64 v4; // x0
  unsigned int v5; // w0
  unsigned int v7; // w19

  input_boost_wq = alloc_workqueue("inputboost_wq", 16, 0);
  if ( !input_boost_wq )
    return 4294967282LL;
  input_boost_work = 0xFFFFFFFE00000LL;
  qword_68408 = (__int64)&qword_68408;
  qword_68410 = (__int64)&qword_68408;
  qword_68418 = (__int64)&do_input_boost;
  input_boost_rem = 0xFFFFFFFE00000LL;
  qword_68428 = (__int64)&qword_68428;
  qword_68430 = (__int64)&qword_68428;
  qword_68438 = (__int64)do_input_boost_rem;
  init_timer_key(&unk_68440, &delayed_work_timer_fn, 0x200000, 0, 0);
  v0 = 0;
  while ( 1 )
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
    {
LABEL_7:
      input_register_handler(&inputboost_input_handler);
      return 0;
    }
    v2 = __clz(__rbit64(v1));
    *(_DWORD *)((char *)&sync_info + *((_QWORD *)&_per_cpu_offset + v2)) = v2;
    v3 = *((_QWORD *)&_per_cpu_offset + v2);
    v4 = cpufreq_cpu_get((unsigned int)v2);
    if ( !v4 )
    {
      printk(&unk_631A3);
      return 4294967293LL;
    }
    v5 = freq_qos_add_request(v4 + 144, (char *)&qos_req + v3, 1, *(unsigned int *)(v4 + 52));
    if ( (v5 & 0x80000000) != 0 )
      break;
    v0 = v2 + 1;
    if ( v2 > 0x1E )
      goto LABEL_7;
  }
  v7 = v5;
  printk(&unk_645F0);
  return v7;
}
