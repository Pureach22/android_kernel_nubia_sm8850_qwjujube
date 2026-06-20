__int64 rmnet_perf_tcp_init()
{
  rmnet_perf_quickack_work = 0xFFFFFFFE00000LL;
  qword_E998 = (__int64)&qword_E998;
  qword_E9A0 = (__int64)&qword_E998;
  qword_E9A8 = (__int64)rmnet_perf_quickack_work_process;
  init_timer_key(&unk_E9B0, &delayed_work_timer_fn, 0x200000, 0, 0);
  return 0;
}
