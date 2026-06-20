__int64 __fastcall trace_raw_output_dfc_flow_info(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x2

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_DWORD *)(v1 + 28) )
      v4 = "add flow";
    else
      v4 = "delete flow";
    trace_event_printf(
      a1,
      "%s: dev=%s bearer_id=%u flow_id=%u ip_type=%d txq=%d\n",
      v4,
      v1 + *(unsigned __int16 *)(v1 + 8),
      *(unsigned __int8 *)(v1 + 12),
      *(unsigned int *)(v1 + 16),
      *(unsigned int *)(v1 + 20),
      *(unsigned int *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
