__int64 hdd_trace_init()
{
  return qdf_trace_register(51, (__int64)hdd_trace_dump);
}
