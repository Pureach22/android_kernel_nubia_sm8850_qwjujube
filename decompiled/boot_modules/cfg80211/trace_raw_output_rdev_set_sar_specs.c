__int64 __fastcall trace_raw_output_rdev_set_sar_specs(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, Set type:%d, num_specs:%d\n",
      (const char *)(v1 + 8),
      *(unsigned __int16 *)(v1 + 40),
      *(unsigned __int16 *)(v1 + 42));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
