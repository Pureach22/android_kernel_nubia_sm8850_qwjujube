__int64 __fastcall trace_raw_output_dfc_flow_ind(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "src=%d [%d]: mid=%u bid=%u grant=%u seq=%u ack=%u anc=%u\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(unsigned __int8 *)(v1 + 16),
      *(unsigned __int8 *)(v1 + 17),
      *(_DWORD *)(v1 + 20),
      *(unsigned __int16 *)(v1 + 24),
      *(unsigned __int8 *)(v1 + 26),
      *(_DWORD *)(v1 + 28));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
