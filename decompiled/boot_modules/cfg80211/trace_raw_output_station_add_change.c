__int64 __fastcall trace_raw_output_station_add_change(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), station mac: %pM, station flags mask: 0x%x, station flags set: 0x%x, station modify mask: 0x%x,"
      " listen interval: %d, aid: %u, plink action: %u, plink state: %u, uapsd queues: %u, vlan:%s\n",
      (const char *)(v1 + 8),
      (const char *)(v1 + 40),
      *(_DWORD *)(v1 + 56),
      (const void *)(v1 + 60),
      *(_DWORD *)(v1 + 68),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80),
      *(unsigned __int16 *)(v1 + 86),
      *(unsigned __int8 *)(v1 + 88),
      *(unsigned __int8 *)(v1 + 89),
      *(unsigned __int8 *)(v1 + 90),
      (const char *)(v1 + 132));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
