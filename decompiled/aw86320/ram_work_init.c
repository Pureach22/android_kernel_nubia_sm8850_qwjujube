__int64 __fastcall ram_work_init(_QWORD *a1)
{
  a1[76] = 0xFFFFFFFE00000LL;
  a1[77] = a1 + 77;
  a1[78] = a1 + 77;
  a1[79] = ram_work_routine;
  init_timer_key(a1 + 80, &delayed_work_timer_fn, 0x200000, 0, 0);
  return queue_delayed_work_on(32, system_wq, a1 + 76, 2000);
}
