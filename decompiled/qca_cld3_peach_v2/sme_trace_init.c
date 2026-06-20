__int64 sme_trace_init()
{
  return qdf_trace_register(52, (__int64)sme_trace_dump);
}
