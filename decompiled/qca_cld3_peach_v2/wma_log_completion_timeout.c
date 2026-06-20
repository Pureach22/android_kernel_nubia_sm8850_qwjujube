__int64 __fastcall wma_log_completion_timeout(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3

  v8 = qdf_trace_msg(
         0x36u,
         8u,
         "%s: Timeout occurred for log completion command",
         a1,
         a2,
         a3,
         a4,
         a5,
         a6,
         a7,
         a8,
         "wma_log_completion_timeout");
  return cds_logging_set_fw_flush_complete(v8, v9, v10, v11);
}
