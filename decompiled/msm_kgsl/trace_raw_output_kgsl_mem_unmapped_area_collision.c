__int64 __fastcall trace_raw_output_kgsl_mem_unmapped_area_collision(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "id=%u len=%lu addr=0x%lx\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 16));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
