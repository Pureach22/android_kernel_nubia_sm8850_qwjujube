void *qdf_dp_trace_clear_buffer()
{
  void *result; // x0

  g_qdf_dp_trace_data = -1;
  dword_73EC18 = 0;
  dword_73EC22 = 2000;
  if ( byte_73EC28 == 1 )
    return memset(&g_qdf_dp_trace_tbl, 0, 0x2AF80u);
  return result;
}
