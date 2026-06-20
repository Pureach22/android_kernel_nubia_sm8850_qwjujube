__int64 __fastcall trace_raw_output_rdev_remain_on_channel(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, wdev(%u), band: %d, freq: %u.%03u, duration: %u\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(unsigned __int16 *)(v1 + 52),
      *(_DWORD *)(v1 + 56));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
