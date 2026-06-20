void *qdf_dp_trace_clear_buffer()
{
  void *result; // x0

  g_qdf_dp_trace_data = -1;
  dword_7F7648 = 0;
  dword_7F7652 = 2000;
  if ( byte_7F7658 == 1 )
    return memset(&g_qdf_dp_trace_tbl, 0, 0x2AF80u);
  return result;
}
