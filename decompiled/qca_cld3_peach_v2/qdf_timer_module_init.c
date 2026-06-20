__int64 qdf_timer_module_init()
{
  qdf_trace_msg(56, 5, "Initializing the QDF MC timer module");
  return qdf_mutex_create((__int64)&persistent_timer_count_lock);
}
