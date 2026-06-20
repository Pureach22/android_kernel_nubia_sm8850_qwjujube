__int64 __fastcall aw9620x_update(_QWORD *a1)
{
  dev_printk(&unk_142BB, a1[6], "[%s:%d] aw9620x update enter\n", "aw9620x_update", 3441);
  a1[65] = 0xFFFFFFFE00000LL;
  a1[66] = a1 + 66;
  a1[67] = a1 + 66;
  a1[68] = aw9620x_update_work;
  init_timer_key(a1 + 69, &delayed_work_timer_fn, 0x200000, 0, 0);
  return queue_delayed_work_on(32, system_wq, a1 + 65, 1250);
}
