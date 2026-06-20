__int64 __fastcall trace_raw_output_rdev_return_int_tx_rx(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, returned %d, tx: %u, rx: %u\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
