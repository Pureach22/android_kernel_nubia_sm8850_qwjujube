__int64 __fastcall qdf_log_dump_at_kernel_level(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char v9; // w19

  v9 = result & 1;
  if ( qdf_log_dump_at_kernel_enable == (result & 1) )
    result = qdf_trace_msg(
               0x38u,
               4u,
               "%s: qdf_log_dump_at_kernel_enable is already %d\n",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "qdf_log_dump_at_kernel_level",
               result & 1);
  qdf_log_dump_at_kernel_enable = v9;
  return result;
}
