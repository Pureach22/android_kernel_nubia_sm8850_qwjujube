__int64 __fastcall trace_raw_output_gmu_event(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "event=%08u ticks=%08u data1=0x%08x data2=0x%08x\n", v1[2], v1[3], v1[4], v1[5]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
