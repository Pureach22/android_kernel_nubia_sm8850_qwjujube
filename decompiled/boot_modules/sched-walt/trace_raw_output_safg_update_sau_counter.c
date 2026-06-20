__int64 __fastcall trace_raw_output_safg_update_sau_counter(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d delta_cntr=%llu,%llu,%llu,%llu delta_time=%llu util=%llu,%llu time=%llu\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 16));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
