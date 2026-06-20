__int64 rmnet_perf_udp_init()
{
  rmnet_perf_udp_work = 0xFFFFFFFE00000LL;
  qword_EA40 = (__int64)&qword_EA40;
  qword_EA48 = (__int64)&qword_EA40;
  qword_EA50 = (__int64)rmnet_perf_udp_work_process;
  init_timer_key(&unk_EA58, &delayed_work_timer_fn, 0x200000, 0, 0);
  return 0;
}
