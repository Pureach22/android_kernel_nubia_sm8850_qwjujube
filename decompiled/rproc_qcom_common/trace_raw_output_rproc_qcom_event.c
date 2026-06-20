__int64 __fastcall trace_raw_output_rproc_qcom_event(__int64 a1)
{
  unsigned __int16 *v1; // x20
  __int64 result; // x0

  v1 = *(unsigned __int16 **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "%s: %s: %s\n", (const char *)v1 + v1[4], (const char *)v1 + v1[6], (const char *)v1 + v1[8]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
