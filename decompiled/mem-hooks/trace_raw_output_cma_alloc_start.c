__int64 __fastcall trace_raw_output_cma_alloc_start(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "name=%s count=%lu align=%u\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(_QWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
