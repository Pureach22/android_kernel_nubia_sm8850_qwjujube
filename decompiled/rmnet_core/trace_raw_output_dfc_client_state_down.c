__int64 __fastcall trace_raw_output_dfc_client_state_down(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "DFC Client[%d] exit: callback %d\n", *(_DWORD *)(v1 + 8), *(_DWORD *)(v1 + 12));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
