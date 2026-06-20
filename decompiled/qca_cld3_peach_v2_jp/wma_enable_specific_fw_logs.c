__int64 __fastcall wma_enable_specific_fw_logs(
        __int64 *a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( !a2 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: start_log pointer is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_enable_specific_fw_logs");
  if ( !a1 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid WMA handle (via %s)",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "__wma_validate_handle",
             "wma_enable_specific_fw_logs");
  if ( *a2 == 1 || *a2 == 4 )
    return wmi_unified_enable_specific_fw_logs_cmd(*a1);
  return qdf_trace_msg(
           0x36u,
           8u,
           "%s: Not connectivity or fw debug ring: %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "wma_enable_specific_fw_logs");
}
