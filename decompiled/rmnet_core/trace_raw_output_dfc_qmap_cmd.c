__int64 __fastcall trace_raw_output_dfc_qmap_cmd(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "mux_id=%u bearer_id=%u seq_num=%u type=%u tran=%u\n",
      *(unsigned __int8 *)(v1 + 8),
      *(unsigned __int8 *)(v1 + 9),
      *(unsigned __int16 *)(v1 + 10),
      *(unsigned __int8 *)(v1 + 12),
      *(_DWORD *)(v1 + 16));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
