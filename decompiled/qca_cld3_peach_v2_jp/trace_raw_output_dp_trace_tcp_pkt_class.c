__int64 __fastcall trace_raw_output_dp_trace_tcp_pkt_class(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "skb=%pK seqnum=%u acknum=%u srcport=%u dstport=%u latency(us)=%llu status=%d\n",
      *(const void **)(v1 + 8),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(unsigned __int16 *)(v1 + 24),
      *(unsigned __int16 *)(v1 + 26),
      *(_QWORD *)(v1 + 32),
      *(unsigned __int8 *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
