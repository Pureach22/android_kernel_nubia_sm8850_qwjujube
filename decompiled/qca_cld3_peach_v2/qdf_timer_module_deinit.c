__int64 qdf_timer_module_deinit()
{
  qdf_trace_msg(56, 5, "De-Initializing the QDF MC timer module");
  return qdf_mutex_destroy((__int64)&persistent_timer_count_lock);
}
