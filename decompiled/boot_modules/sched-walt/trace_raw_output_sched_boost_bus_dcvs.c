__int64 __fastcall trace_raw_output_sched_boost_bus_dcvs(__int64 a1)
{
  unsigned __int8 *v1; // x20
  __int64 result; // x0

  v1 = *(unsigned __int8 **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "rotation_enabled=%d storage_boosted=%d trailblazer_boost_active=%d sbt_boost_active=%d\n",
      v1[8],
      v1[9],
      v1[10],
      v1[11]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
