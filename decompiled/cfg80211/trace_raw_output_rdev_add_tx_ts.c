__int64 __fastcall trace_raw_output_rdev_add_tx_ts(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), %pM, TSID %d, UP %d, time %d\n",
      (const char *)(v1 + 8),
      (const char *)(v1 + 40),
      *(_DWORD *)(v1 + 56),
      (const void *)(v1 + 60),
      *(unsigned __int8 *)(v1 + 66),
      *(unsigned __int8 *)(v1 + 67),
      *(unsigned __int16 *)(v1 + 68));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
