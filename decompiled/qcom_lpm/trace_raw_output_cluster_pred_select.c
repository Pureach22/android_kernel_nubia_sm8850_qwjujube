__int64 __fastcall trace_raw_output_cluster_pred_select(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "idx:%d next_wakeup:%llu restrict_idx:%d pred:%d pred_us:%llu\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_QWORD *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
