__int64 htc_credit_history_init()
{
  g_htc_credit_lock = 0;
  qword_92C328 = 0;
  g_htc_credit_history_idx = 0;
  g_htc_credit_history_length = 0;
  _qdf_minidump_log((__int64)&htc_credit_history_buffer, 24576, (__int64)"htc_credit");
  ((void (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
    "htc_credit",
    &htc_credit_history_buffer,
    24576);
  ((void (__fastcall *)(const char *, int *, __int64))qdf_ssr_driver_dump_register_region)(
    "htc_credit_history_idx",
    &g_htc_credit_history_idx,
    4);
  return ((__int64 (__fastcall *)(const char *, int *, __int64))qdf_ssr_driver_dump_register_region)(
           "htc_credit_history_length",
           &g_htc_credit_history_length,
           4);
}
