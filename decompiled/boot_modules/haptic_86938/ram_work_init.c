__int64 __fastcall ram_work_init(_QWORD *a1)
{
  a1[120] = 0xFFFFFFFE00000LL;
  a1[121] = a1 + 121;
  a1[122] = a1 + 121;
  a1[123] = ram_work_routine;
  init_timer_key(a1 + 124, &delayed_work_timer_fn, 0x200000, 0, 0);
  return queue_delayed_work_on(32, system_wq, a1 + 120, 2000);
}
