void *qdf_trace_init()
{
  g_qdf_trace_data_0 = -1;
  g_qdf_trace_data_1 = -1;
  g_qdf_trace_data_2 = 0;
  g_qdf_trace_data_4 = 1;
  g_qdf_trace_data_3 = 0;
  memset(qdf_trace_cb_table, 0, 0x538u);
  return memset(qdf_trace_restore_cb_table, 0, 0x538u);
}
