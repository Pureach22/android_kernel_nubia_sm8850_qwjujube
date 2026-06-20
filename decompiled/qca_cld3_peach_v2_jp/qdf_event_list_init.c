void qdf_event_list_init()
{
  qdf_wait_event_list = (__int64)&qdf_wait_event_list;
  qword_7168E8 = (__int64)&qdf_wait_event_list;
  qword_7168F0 = 0xA00000000LL;
  qdf_wait_event_lock = 0;
  qword_716900 = 0;
}
