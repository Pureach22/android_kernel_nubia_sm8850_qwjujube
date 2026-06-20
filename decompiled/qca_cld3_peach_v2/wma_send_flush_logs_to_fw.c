__int64 __fastcall wma_send_flush_logs_to_fw(__int64 *a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = wmi_unified_flush_logs_to_fw_cmd(*a1);
  if ( !(_DWORD)result )
  {
    result = qdf_mc_timer_start((__int64)(a1 + 343), 0x1F4u);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to start the log completion timer",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "wma_send_flush_logs_to_fw");
  }
  return result;
}
