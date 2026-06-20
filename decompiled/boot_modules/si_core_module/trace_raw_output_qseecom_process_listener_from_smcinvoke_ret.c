__int64 __fastcall trace_raw_output_qseecom_process_listener_from_smcinvoke_ret(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "process_listener_from_smcinvoke_ret response_type=0x%08llx result=%d ret=%d\n",
      *(_QWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
