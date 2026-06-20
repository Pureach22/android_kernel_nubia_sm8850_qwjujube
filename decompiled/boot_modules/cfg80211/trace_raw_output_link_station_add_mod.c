__int64 __fastcall trace_raw_output_link_station_add_mod(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), station mac: %pM, link mac: %pM, link id: %u\n",
      (const char *)(v1 + 8),
      (const char *)(v1 + 40),
      *(_DWORD *)(v1 + 56),
      (const void *)(v1 + 60),
      (const void *)(v1 + 66),
      *(_DWORD *)(v1 + 72));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
