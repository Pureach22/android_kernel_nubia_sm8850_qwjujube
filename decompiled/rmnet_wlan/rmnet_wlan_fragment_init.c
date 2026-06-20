__int64 rmnet_wlan_fragment_init()
{
  rmnet_wlan_fragment_work = 0xFFFFFFFE00000LL;
  qword_CC50 = (__int64)&qword_CC50;
  qword_CC58 = (__int64)&qword_CC50;
  qword_CC60 = (__int64)rmnet_wlan_fragment_work_process;
  init_timer_key(&unk_CC68, &delayed_work_timer_fn, 0x200000, 0, 0);
  return 0;
}
