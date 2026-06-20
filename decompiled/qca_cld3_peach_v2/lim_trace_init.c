__int64 lim_trace_init()
{
  return qdf_trace_register(53, (__int64)&lim_trace_dump);
}
