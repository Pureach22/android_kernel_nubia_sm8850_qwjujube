__int64 __fastcall trace_raw_output_si_objcet_do_ctx_invoke_ret(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "oic_context_id=0x%08x oic_flags=0x%02x i=%d response_type=0x%08llx ret=%d\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
