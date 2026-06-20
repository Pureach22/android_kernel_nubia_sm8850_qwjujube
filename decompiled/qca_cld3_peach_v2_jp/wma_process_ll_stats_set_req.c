__int64 __fastcall wma_process_ll_stats_set_req(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x2
  __int64 result; // x0

  v10 = "%s: input pointer is NULL";
  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 )
    goto LABEL_5;
  result = wmi_unified_process_ll_stats_set_cmd(*a1);
  if ( (_DWORD)result )
  {
    v10 = "%s: Failed to send set link stats request";
LABEL_5:
    qdf_trace_msg(0x36u, 2u, v10, a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_ll_stats_set_req");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
