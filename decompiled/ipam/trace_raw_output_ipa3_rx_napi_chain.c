__int64 __fastcall trace_raw_output_ipa3_rx_napi_chain(__int64 a1)
{
  const void **v1; // x20
  __int64 result; // x0

  v1 = *(const void ***)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "first_skb=0x%pK prev_skb=0x%pK rx_skb=0x%pK\n", v1[1], v1[2], v1[3]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
