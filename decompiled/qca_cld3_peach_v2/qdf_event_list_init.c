void qdf_event_list_init()
{
  qdf_wait_event_list = (__int64)&qdf_wait_event_list;
  qword_7CF318 = (__int64)&qdf_wait_event_list;
  qword_7CF320 = 0xA00000000LL;
  qdf_wait_event_lock = 0;
  qword_7CF330 = 0;
}
