__int64 htc_control_rx_complete()
{
  __int64 result; // x0

  if ( (dword_B0B4 & 1) != 0 )
    return qdf_trace_msg(56, 2, "%s: Invalid call to  htc_control_rx_complete\n", "htc_control_rx_complete");
  return result;
}
