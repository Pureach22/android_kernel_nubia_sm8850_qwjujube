__int64 __fastcall trace_raw_output_ipa_tx_dp(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "dev=%s skbaddr=%p protocol=0x%04x len=%u data_len=%u client=%lu\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(const void **)(v1 + 16),
      *(unsigned __int16 *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
