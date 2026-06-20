__int64 __fastcall trace_raw_output_drv_twt_teardown_request(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s sta:%pM flowid:%d\n",
      (const char *)(v1 + 8),
      (const void *)(v1 + 40),
      *(unsigned __int8 *)(v1 + 46));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
