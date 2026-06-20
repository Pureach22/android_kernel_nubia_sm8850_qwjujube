__int64 __fastcall trace_raw_output_tracing_eva_frame_from_sw(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  int v4; // [xsp+0h] [xbp-10h]

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 36);
    trace_event_printf(
      a1,
      "AON_TIMESTAMP: %llu %s session_id = 0x%08x stream_id = 0x%08x packet_id = 0x%08x command_name = %s transaction_id "
      "= 0x%016llx ktid = %llu\n",
      *(_QWORD *)(v1 + 8),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 16)),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 32)),
      v4,
      *(_QWORD *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
