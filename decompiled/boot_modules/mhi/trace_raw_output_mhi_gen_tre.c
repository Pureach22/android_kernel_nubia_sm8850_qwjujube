__int64 __fastcall trace_raw_output_mhi_gen_tre(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s: Chan: %d TRE: 0x%p TRE buf: 0x%llx DWORD0: 0x%08x DWORD1: 0x%08x\n\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(_DWORD *)(v1 + 12),
      *(const void **)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 36));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
