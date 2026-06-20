__int64 __fastcall trace_raw_output_rdev_nan_change_conf(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, wdev(%u), master preference: %u, bands: 0x%0x, changes: %x\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(unsigned __int8 *)(v1 + 44),
      *(unsigned __int8 *)(v1 + 45),
      *(_DWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
