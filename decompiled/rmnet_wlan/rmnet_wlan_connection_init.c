__int64 rmnet_wlan_connection_init()
{
  rmnet_wlan_connection_work = 0xFFFFFFFE00000LL;
  qword_CBD8 = (__int64)&qword_CBD8;
  qword_CBE0 = (__int64)&qword_CBD8;
  qword_CBE8 = (__int64)rmnet_wlan_connection_work_process;
  init_timer_key(&unk_CBF0, &delayed_work_timer_fn, 0x200000, 0, 0);
  return 0;
}
