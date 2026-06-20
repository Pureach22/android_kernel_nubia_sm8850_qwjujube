__int64 __fastcall wma_process_set_mas(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  const char *v10; // x2

  if ( !a1 )
  {
    v10 = "%s: Invalid input to enable/disable MAS";
    return qdf_trace_msg(0x36u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wma_process_set_mas");
  }
  v9 = *a1;
  if ( (unsigned int)wma_set_enable_disable_mcc_adaptive_scheduler(*a1, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: Unable to enable/disable MAS";
    return qdf_trace_msg(0x36u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wma_process_set_mas");
  }
  return qdf_trace_msg(0x36u, 8u, "%s: Value is %d", a2, a3, a4, a5, a6, a7, a8, a9, "wma_process_set_mas", v9);
}
