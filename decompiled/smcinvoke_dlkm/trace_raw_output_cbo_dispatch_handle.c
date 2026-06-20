__int64 __fastcall trace_raw_output_cbo_dispatch_handle(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "ob_name=%s cb_context_id=0x%08x cb_u_handle=0x%016llx op=0x%08lx\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
