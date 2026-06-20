__int64 __fastcall trace_raw_output_dp_tx_enqueue(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "skb=%pK hp=%d ring_id=%d coalesce=%d\n",
      *(const void **)(v1 + 8),
      *(_DWORD *)(v1 + 16),
      *(unsigned __int8 *)(v1 + 20),
      *(_DWORD *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
