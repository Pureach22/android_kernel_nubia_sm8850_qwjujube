__int64 __fastcall trace_raw_output_sched_update_pred_demand(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid=%d comm=%s runtime=%u cpu=%d pred_demand_scaled=%u start=%d first=%d final=%d (buckets: %u %u %u %u %u %u %u %"
      "u %u %u %u %u %u %u %u %u)\n",
      *(_DWORD *)(v1 + 24),
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(unsigned __int8 *)(v1 + 36),
      *(unsigned __int8 *)(v1 + 37),
      *(unsigned __int8 *)(v1 + 38),
      *(unsigned __int8 *)(v1 + 39),
      *(unsigned __int8 *)(v1 + 40),
      *(unsigned __int8 *)(v1 + 41),
      *(unsigned __int8 *)(v1 + 42),
      *(unsigned __int8 *)(v1 + 43),
      *(unsigned __int8 *)(v1 + 44),
      *(unsigned __int8 *)(v1 + 45),
      *(unsigned __int8 *)(v1 + 46),
      *(unsigned __int8 *)(v1 + 47),
      *(unsigned __int8 *)(v1 + 48),
      *(unsigned __int8 *)(v1 + 49),
      *(unsigned __int8 *)(v1 + 50),
      *(unsigned __int8 *)(v1 + 51));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
