__int64 __fastcall trace_raw_output_memlat_dev_meas(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "dev: %s, id=%u, inst=%lu, mem=%lu, freq=%lu, stall=%u, wb=%u, ratio=%u, fe_stall=%u\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(_DWORD *)(v1 + 12),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 52));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
